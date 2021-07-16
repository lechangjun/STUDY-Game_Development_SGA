#include "stdafx.h"
#include "Systems/Device.h"
#include "Objects/Background.h"
#include "Objects/Bobble.h"

#include <time.h>

Background* BackGround;
Sprite* Arrow;
Bobble* FirstBobble;
Bobble* Bobbles;
vector<Bobble *> BobbleVec;

D3DXVECTOR2 position = D3DXVECTOR2(400, 100);
float angleArrow = 0.0f;

void InitScene()
{
	srand(unsigned int(time(NULL)));
	wstring shaderFile = L"../_Shaders/008_Sprite.fx";

	BackGround = new Background(shaderFile);

	Arrow = new Sprite(Textures + L"PB/Arrow.png", shaderFile);
	Arrow->Position(520, 145);
	Arrow->Scale(60, 110);

	//FirstBobble = new Bobble(Textures + L"PB/Gray.png", shaderFile, D3DXVECTOR2(400,45), angleArrow, 0, D3DXVECTOR2(0,0));
	//BobbleVec.push_back(FirstBobble);
}

void DestroyScene()
{
	SAFE_DELETE(BackGround);
	SAFE_DELETE(Arrow);
	for (Bobble* vec : BobbleVec)
		SAFE_DELETE(vec);
}

D3DXMATRIX V, P;


void Update()
{
	//화살 각도 바꿈
	if (Key->Press(VK_LEFT) && angleArrow < 45.0f)
	{
		angleArrow += 0.01f;
		Arrow->ToRotationZ(angleArrow);
	}
	if (Key->Press(VK_RIGHT) && angleArrow > -45.0f)
	{
		angleArrow -= 0.01f;
		Arrow->ToRotationZ(angleArrow);
	}

	//버블 생성
	if (Key->Down(VK_SPACE))
	{
		wstring colorFile; //텍스쳐 파일을 랜덤으로 선택
		int colorNum;

		if (rand() % 5 == 4)
		{
			colorFile = Textures + L"PB/Gray.png";
			colorNum = GRAY;
		}
		else if (rand() % 4 == 3)
		{
			colorFile = Textures + L"PB/Yellow.png";
			colorNum = YELLOW;
		}
		else if (rand() % 3 == 2)
		{
			colorFile = Textures + L"PB/Purple.png";
			colorNum = PURPLE;
		}
		else if (rand() % 2 == 1)
		{
			colorFile = Textures + L"PB/Blue.png";
			colorNum = BLUE;
		}
		else if (rand() % 1 == 0)
		{
			colorFile = Textures + L"PB/Red.png";
			colorNum = RED;
		}

		Bobbles = new Bobble(colorFile, Shaders + L"008_Sprites.fx", position, angleArrow, colorNum);
		BobbleVec.push_back(Bobbles);
	}

	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Prjection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);

	BackGround->Update(V, P);
	Arrow->Update(V, P);
	for (Bobble* vec : BobbleVec)
		vec->Update(V, P);
}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(0, 0, 0, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		BackGround->Render();
		Arrow->Render();
		for (Bobble* vec : BobbleVec)
			vec->Render();
	}
	ImGui::Render();
	SwapChain->Present(0, 0);
}