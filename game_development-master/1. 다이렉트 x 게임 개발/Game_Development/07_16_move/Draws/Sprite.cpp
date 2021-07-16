#include "stdafx.h"
#include "Sprite.h"

Sprite::Sprite(wstring textureFile, wstring shaderFile)
{
	Initialize(textureFile, shaderFile, 0, 0, 0, 0);
}

Sprite::Sprite(wstring textureFile, wstring shaderFile, float endX, float endY)
{
	Initialize(textureFile, shaderFile, 0, 0, endX, endY);
}

Sprite::Sprite(wstring textureFile, wstring shaderFile, float startX, float startY, float endX, float endY)
{
	Initialize(textureFile, shaderFile, startX, startY, endX, endY);
}

void Sprite::Initialize(wstring spriteFile, wstring shaderFile, float startX, float startY, float endX, float endY)
{
	radian = 0.0f;

	textureFile = spriteFile;

	shader = new Shader(shaderFile);
	srv = Sprites::Load(spriteFile); //�˾Ƽ� srv�� ��
	shader->AsShaderResource("Map")->SetResource(srv);

	HRESULT hr; //HRESULT: ������� ������ (SUCCEEDE0 D/FAILED 1)
	D3DX11_IMAGE_INFO info;
	hr = D3DX11GetImageInfoFromFile(spriteFile.c_str(), NULL, &info, NULL); //�ش� ���Ͽ� ���� ���� ����
		//spriteFile.c_str(): sprite File�� �̸�
	assert(SUCCEEDED(hr));

	startX = (startX > 0) ? startX / (float)info.Width : 0.0f;
	startY = (startY > 0) ? startY / (float)info.Height : 0.0f;

	endX = (endX > 0) ? endX / (float)info.Width : 1.0f;
	endY = (endY > 0) ? endY / (float)info.Height : 1.0f;

	Vertex vertices[6];

	vertices[0].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	vertices[1].Position = D3DXVECTOR3(-0.5f, +0.5f, 0.0f);
	vertices[2].Position = D3DXVECTOR3(+0.5f, -0.5f, 0.0f);
	vertices[3].Position = D3DXVECTOR3(+0.5f, -0.5f, 0.0f);
	vertices[4].Position = D3DXVECTOR3(-0.5f, +0.5f, 0.0f);
	vertices[5].Position = D3DXVECTOR3(+0.5f, +0.5f, 0.0f);

	//UV��ǥ
	vertices[0].Uv = D3DXVECTOR2(startX, endY); //0, 1
	vertices[1].Uv = D3DXVECTOR2(startX, startY); //0, 0
	vertices[2].Uv = D3DXVECTOR2(endX, endY); //1, 1
	vertices[3].Uv = D3DXVECTOR2(endX, endY); //1, 1
	vertices[4].Uv = D3DXVECTOR2(startX, startY); //0, 0
	vertices[5].Uv = D3DXVECTOR2(endX, startY); //1, 0

	float sizeX = (endX > 0) ? endX : 1.0f;
	sizeX -= startX;
	sizeX *= (float)info.Width;

	float sizeY = (endY > 0) ? endY : 1.0f;
	sizeY -= startY;
	sizeY *= (float)info.Height;

	scale = D3DXVECTOR2(sizeX, sizeY);
	UpdateWorld();

	//Create Vertex Buffer
	{
		D3D11_BUFFER_DESC desc = { 0 };
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * 6;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA data = { 0 };
		data.pSysMem = vertices;

		HRESULT hr = Device->CreateBuffer(&desc, &data, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}
}

Sprite::~Sprite()
{
	SAFE_DELETE(shader);
	SAFE_RELEASE(vertexBuffer);

	Sprites::Remove(textureFile);
}

void Sprite::Update(D3DXMATRIX& V, D3DXMATRIX& P)
{
	shader->AsMatrix("View")->SetMatrix(V);
	shader->AsMatrix("Projection")->SetMatrix(P);
}

void Sprite::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	DeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	shader->Draw(0, 0, 6);
}

void Sprite::Position(float x, float y)
{
	Position(D3DXVECTOR2(x, y));
}

void Sprite::Position(D3DXVECTOR2 & vec)
{
	position = vec;

	UpdateWorld();
}

void Sprite::Scale(float x, float y)
{
	Scale(D3DXVECTOR2(x, y));
}

void Sprite::Scale(D3DXVECTOR2 & vec)
{
	scale = vec;

	UpdateWorld();
}

//������ radian���� �ٲ�
void Sprite::ToRotationZ(float angle)
{
	radian = Math::ToRadian(angle);

	UpdateWorld();
}

//RotationZ �߰�
void Sprite::UpdateWorld()
{
	D3DXMATRIX W, S, R, T;
	D3DXMatrixScaling(&S, scale.x, scale.y, 1.0f);
	D3DXMatrixRotationZ(&R, radian);
	D3DXMatrixTranslation(&T, position.x, position.y, 0.0f);
	W = S * R * T;

	shader->AsMatrix("World")->SetMatrix(W);
}

//----------------------------------------------------------------------------------------
// Sprites (SpriteŬ������, SpritesŬ������ friend class�� Sprites Ŭ������ ���� ���� ������)
//----------------------------------------------------------------------------------------

map<wstring, Sprites::SpriteDesc> Sprites::spriteMap; //static ������ ���, ������ ���� ������ �ѹ� �� �����ؾ���
//Ŭ���� �ڿ� scope(::) ����

//SRV�� Load�Լ��� ��������, Remove�Լ��� ����
//������ ref ī��Ʈ�� �÷��ְ�
//������ ���� ������ (���� �̹����� ���� ������;)
ID3D11ShaderResourceView * Sprites::Load(wstring file) 
{
	//<--spriteMap�� ������ ������--> (file�� key�� ���� ������ 0���� ũ��)
	if (spriteMap.count(file) > 0)
	{
		spriteMap[file].RefCount++; //reference count�� �÷��ְ�, 
		return spriteMap[file].SRV; //SRV ����
	}
	
	//<--spriteMap�� ������ ������ ������-->
	HRESULT hr;
	ID3D11ShaderResourceView* srv;
	hr = D3DX11CreateShaderResourceViewFromFile(Device, file.c_str(), NULL, NULL, &srv, NULL); //c_str: const char*
	assert(SUCCEEDED(hr));
	SpriteDesc desc;
	desc.RefCount++; //reference count �÷���
	desc.SRV = srv;
	spriteMap[file] = desc; //key: ��������Ʈfile //value: desc //desc�ȿ� RefCount�� SRV����
	return desc.SRV; //SRV ����
}

void Sprites::Remove(wstring file)
{
	UINT count = spriteMap.count(file); //1 or 0 (Ű �� �ߺ��Ұ�)
	assert(count > 0); //�����Ͱ� ������ ����

	spriteMap[file].RefCount--; //reference count -1

	//�ٸ��� �ּ� ����
	if (spriteMap[file].RefCount < 1) //Ű���� file�� ����� ����� ReftCount�� 1���� ������
	{
		SAFE_RELEASE(spriteMap[file].SRV); //����� SRV �޸� ��ȯ��
		spriteMap.erase(file); //map���� Ű���� file�� ������ ����
	}
}