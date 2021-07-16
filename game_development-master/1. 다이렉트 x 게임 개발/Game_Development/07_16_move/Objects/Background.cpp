#include "stdafx.h"
#include "Background.h"

Background::Background(wstring shaderFile)
{
	wstring textureFile = L"";

	textureFile = L"../_Textures/PB/bg.png";
	bg = new Sprite(textureFile, shaderFile, 344, 530, 670, 767);
}

Background::~Background()
{
	SAFE_DELETE(bg);
}

void Background::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	bg->Update(V, P);
}

void Background::Render()
{
	bg->Position(400, 300);
	bg->Scale(800, 600);
	bg->Render();
}