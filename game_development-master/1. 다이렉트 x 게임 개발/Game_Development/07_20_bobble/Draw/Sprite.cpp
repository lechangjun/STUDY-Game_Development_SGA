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

	shader = new Shader(shaderFile); //쉐이더 생성

	srv = Sprites::Load(spriteFile); //srv 에 Load 반환 값 적용
	shader->AsShaderResource("Map")->SetResource(srv); //쉐이더에 "Map" 으로 된 srv 설정

	HRESULT hr;
	D3DX11_IMAGE_INFO info; //이미지 정보 ? 값
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

	startX = (startX > 0) ? startX / (float)info.Width : 0.0f; //startX 가 0보다 크다면
	// startX를 이미지 너비로 나눈 값을 대입하고 0보다 작다면 0을 대입한다.
	startY = (startY > 0) ? startY / (float)info.Height : 0.0f; // startY 가 0보다 크면 
	// startY를 이미지 높이로 나눈 값을 대입하고 0보다 작다면 0을 대입한다.

	endX = (endX > 0) ? endX / (float)info.Width : 1.0f;//endX 가 0보다 크다면
	// endX를 이미지 너비로 나눈 값을 대입하고 0보다 작다면 1을 대입한다.
	endY = (endY > 0) ? endY / (float)info.Height : 1.0f;// endY 가 0보다 크면 
	// endY를 이미지 높이로 나눈 값을 대입하고 0보다 작다면 1을 대입한다.

	Rotation(rotation); //회전값 초기화

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
	//endX가 0보다 크다면 endX * 너비 값을 sizeX에 대입하고 0보다 작다면 너비값을 넣어준다
	sizeX -= startX * (float)info.Width;
	//sizeX 값에 startX * 너비  값을 뺀다.
	float sizeY = (endY > 0) ? endY * (float)info.Height : (float)info.Height;
	//endㅛ가 0보다 크다면 endㅛ * 높이 값을 sizeㅛ에 대입하고 0보다 작다면 높이값을 넣어준다
	sizeY -= startY * (float)info.Height;
	//sizeY 값에 startY * 높이  값을 뺀다.
	scale = D3DXVECTOR2(sizeX, sizeY);
	//보이는 이미지 크기
	textureSize = D3DXVECTOR2((float)info.Width, (float)info.Height);
	//실제 사이즈
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
	D3DXMATRIX W, S, R, T; //라디안추가
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
//static 변수는 cpp에서 한번더 선언해야함.
ID3D11ShaderResourceView * Sprites::Load(wstring file)
{
	if (spriteMap.count(file) > 0) //spriteMap 가 0보다 크다면
	{
		spriteMap[file].RefCount++; //key값 RefCount을 하나 늘려준다.
		return spriteMap[file].SRV; //SRV에 적용
	}

	HRESULT hr;
	ID3D11ShaderResourceView* srv;
	hr = D3DX11CreateShaderResourceViewFromFile(Device, file.c_str(), NULL, NULL, &srv, NULL);
	assert(SUCCEEDED(hr));//오류 확인
	
	SpriteDesc desc; //구조체
	desc.RefCount++; //구조체 안의 Ref값 증가
	desc.SRV = srv;  //구조체 안의 SRV값을 srv에 대입
	spriteMap[file] = desc; //spriteMap 에 적용

	return desc.SRV;
}

void Sprites::Remove(wstring file)
{
	UINT count = spriteMap.count(file);
	assert(count > 0); //spriteMap 이 존재한다면

	spriteMap[file].RefCount--; //RefCount 값을 하나 줄인다.
	if (spriteMap[file].RefCount < 1) //spriteMap 이 1보다 작다면
	{
		SAFE_RELEASE(spriteMap[file].SRV);

		spriteMap.erase(file); //spriteMap 삭제
	}
}
