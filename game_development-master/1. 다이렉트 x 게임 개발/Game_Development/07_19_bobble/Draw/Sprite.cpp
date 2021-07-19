#include "stdafx.h"
#include "Sprite.h"

//-----------------------------------------------------------------------------------------------
// Sprite
//-----------------------------------------------------------------------------------------------

Sprite::Sprite(wstring textureFile, wstring shaderFile)
{
	Initialize(textureFile, shaderFile, 0, 0, 0, 0, 0);
}

Sprite::Sprite(wstring textureFile, wstring shaderFile, float endX, float endY)
{
	Initialize(textureFile, shaderFile, 0, 0, endX, endY, 0);
}

Sprite::Sprite(wstring textureFile, wstring shaderFile, float startX, float startY, float endX, float endY, float rotation)
{
	Initialize(textureFile, shaderFile, startX, startY, endX, endY, 0);
}



void Sprite::Initialize(wstring spriteFile, wstring shaderFile, float startX, float startY, float endX, float endY, float rotation)
{
	
	textureFile = spriteFile;

	shader = new Shader(shaderFile); //���̴� ����

	srv = Sprites::Load(spriteFile); //srv �� Load ��ȯ �� ����
	shader->AsShaderResource("Map")->SetResource(srv); //���̴��� "Map" ���� �� srv ����

	HRESULT hr;
	D3DX11_IMAGE_INFO info; //�̹��� ���� ? ��
	/*typedef struct D3DX11_IMAGE_INFO
	{
		UINT                        Width;
		UINT                        Height;
		UINT                        Depth;
		UINT                        ArraySize;
		UINT                        MipLevels;
		UINT                        MiscFlags;
		DXGI_FORMAT                 Format;
		D3D11_RESOURCE_DIMENSION    ResourceDimension;
		D3DX11_IMAGE_FILE_FORMAT    ImageFileFormat;
	} D3DX11_IMAGE_INFO;*/
	hr = D3DX11GetImageInfoFromFile(spriteFile.c_str(), NULL, &info, NULL);
	assert(SUCCEEDED(hr));

	startX = (startX > 0) ? startX / (float)info.Width : 0.0f; //startX �� 0���� ũ�ٸ�
	// startX�� �̹��� �ʺ�� ���� ���� �����ϰ� 0���� �۴ٸ� 0�� �����Ѵ�.
	startY = (startY > 0) ? startY / (float)info.Height : 0.0f; // startY �� 0���� ũ�� 
	// startY�� �̹��� ���̷� ���� ���� �����ϰ� 0���� �۴ٸ� 0�� �����Ѵ�.

	endX = (endX > 0) ? endX / (float)info.Width : 1.0f;//endX �� 0���� ũ�ٸ�
	// endX�� �̹��� �ʺ�� ���� ���� �����ϰ� 0���� �۴ٸ� 1�� �����Ѵ�.
	endY = (endY > 0) ? endY / (float)info.Height : 1.0f;// endY �� 0���� ũ�� 
	// endY�� �̹��� ���̷� ���� ���� �����ϰ� 0���� �۴ٸ� 1�� �����Ѵ�.

	Rotation(rotation); //ȸ���� �ʱ�ȭ

	Vertex vertices[6];
	vertices[0].Position = D3DXVECTOR3(-0.5f, -0.5f, 0.0f);
	vertices[1].Position = D3DXVECTOR3(-0.5f, +0.5f, 0.0f);
	vertices[2].Position = D3DXVECTOR3(+0.5f, -0.5f, 0.0f);
	vertices[3].Position = D3DXVECTOR3(+0.5f, -0.5f, 0.0f);
	vertices[4].Position = D3DXVECTOR3(-0.5f, +0.5f, 0.0f);
	vertices[5].Position = D3DXVECTOR3(+0.5f, +0.5f, 0.0f);

	vertices[0].Uv = D3DXVECTOR2(startX, endY);
	vertices[1].Uv = D3DXVECTOR2(startX, startY);
	vertices[2].Uv = D3DXVECTOR2(endX, endY);
	vertices[3].Uv = D3DXVECTOR2(endX, endY);
	vertices[4].Uv = D3DXVECTOR2(startX, startY);
	vertices[5].Uv = D3DXVECTOR2(endX, startY);

	float sizeX = (endX > 0) ? endX * (float)info.Width : (float)info.Width;
	//endX�� 0���� ũ�ٸ� endX * �ʺ� ���� sizeX�� �����ϰ� 0���� �۴ٸ� �ʺ��� �־��ش�
	sizeX -= startX * (float)info.Width;
	//sizeX ���� startX * �ʺ�  ���� ����.
	float sizeY = (endY > 0) ? endY * (float)info.Height : (float)info.Height;
	//end�˰� 0���� ũ�ٸ� end�� * ���� ���� size�˿� �����ϰ� 0���� �۴ٸ� ���̰��� �־��ش�
	sizeY -= startY * (float)info.Height;
	//sizeY ���� startY * ����  ���� ����.
	scale = D3DXVECTOR2(sizeX, sizeY);
	//���̴� �̹��� ũ��
	textureSize = D3DXVECTOR2((float)info.Width, (float)info.Height);
	//���� ������
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



void Sprite::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	shader->AsMatrix("View")->SetMatrix(V);
	shader->AsMatrix("Projection")->SetMatrix(P);
}

void Sprite::Render()
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	DeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	
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

void Sprite::Rotation(float angle)
{
	radian = Math::ToRadian(angle);
	UpdateWorld();
}

float Sprite::Rotation()
{
	float angle = Math::ToDegree(radian);
	//-70.0f < angle < 70.0f;
	return angle;
}



void Sprite::UpdateWorld()
{
	//Wolrd
	D3DXMATRIX W, S, R, T; //�����߰�
	D3DXMatrixScaling(&S, scale.x, scale.y, 1.0f);
	D3DXMatrixRotationZ(&R, radian);
	D3DXMatrixTranslation(&T, position.x, position.y, 0.0f);

	W = S * R* T;

	shader->AsMatrix("World")->SetMatrix(W);

}


//-----------------------------------------------------------------------------------------------
// Sprites
//-----------------------------------------------------------------------------------------------

map<wstring, Sprites::SpriteDesc> Sprites::spriteMap;
//static ������ cpp���� �ѹ��� �����ؾ���.
ID3D11ShaderResourceView * Sprites::Load(wstring file)
{
	if (spriteMap.count(file) > 0) //spriteMap �� 0���� ũ�ٸ�
	{
		spriteMap[file].RefCount++; //key�� RefCount�� �ϳ� �÷��ش�.
		return spriteMap[file].SRV; //SRV�� ����
	}

	HRESULT hr;
	ID3D11ShaderResourceView* srv;
	hr = D3DX11CreateShaderResourceViewFromFile(Device, file.c_str(), NULL, NULL, &srv, NULL);
	assert(SUCCEEDED(hr));//���� Ȯ��
	
	SpriteDesc desc; //����ü
	desc.RefCount++; //����ü ���� Ref�� ����
	desc.SRV = srv;  //����ü ���� SRV���� srv�� ����
	spriteMap[file] = desc; //spriteMap �� ����

	return desc.SRV;
}

void Sprites::Remove(wstring file)
{
	UINT count = spriteMap.count(file);
	assert(count > 0); //spriteMap �� �����Ѵٸ�

	spriteMap[file].RefCount--; //RefCount ���� �ϳ� ���δ�.
	if (spriteMap[file].RefCount < 1) //spriteMap �� 1���� �۴ٸ�
	{
		SAFE_RELEASE(spriteMap[file].SRV);

		spriteMap.erase(file); //spriteMap ����
	}
}
