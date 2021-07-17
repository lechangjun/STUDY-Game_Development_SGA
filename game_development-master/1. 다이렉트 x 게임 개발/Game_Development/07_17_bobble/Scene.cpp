#include "stdafx.h"
#include "Device.h"
#include "Objects/Background.h"
#include "Objects/Bubble.h"

Background* bg;
Sprite* mach;
Sprite* aw;
vector<Bubble*>bubbles;

void InitScene()
{
	wstring shaderFile = L"../_Shaders/008_Sprite.fx";

	bg = new Background(L"../_Shaders/008_Sprite.fx"); //배경

	mach = new Sprite(L"../_Textures/PuzzleBobble/PuzzleBobble.png", shaderFile, 8, 713, 84, 759);
	//기계
	mach->Position(Width/2, 46);
	mach->Scale(100, 100);

	aw = new Sprite(L"../_Textures/PuzzleBobble/PuzzleBobble.png", shaderFile, 12, 488, 34, 543);
	//화살
	aw->Position(Width/2, 76);
	aw->Scale(50, 125);
}

void DestroyScene()
{
	SAFE_DELETE(bg);
	SAFE_DELETE(mach);
	SAFE_DELETE(aw);
	for (Bubble* bubble : bubbles)
		SAFE_DELETE(bubble);
}

D3DXMATRIX V, P;
void Update()
{
	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Prjection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);

	if (Key->Press(VK_LEFT) && aw->Rotation() < 87.0f)
		aw->Rotation(aw->Rotation() + 0.05f);
	//화살표 회전(왼쪽)
	if (Key->Press(VK_RIGHT) && aw->Rotation() > -87.0f)
		aw->Rotation(aw->Rotation() - 0.05f);
	//화살표 회전(오른쪽)
	if (Key->Down(VK_SPACE))
	{ //버블 생성 및 발사
		wstring file = Shaders + L"008_Sprite.fx";

		float angle = aw->Rotation() + 90;
		Bubble* bubble = new Bubble(file, aw->Position(), angle, 0.5);
		bubbles.push_back(bubble);
	}

	bg->Update(V, P);

	mach->Update(V, P);
	aw->Update(V, P);

	for (Bubble* bubble : bubbles)
		bubble->Update(V, P);
}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(1, 1, 1, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		//생성 순서
		//배경->장치->화살표->버블
		bg->Render();
		mach->Render();
		aw->Render();

		for (Bubble* bubble : bubbles)
			bubble->Render();
	}
	ImGui::Render();
	SwapChain->Present(0, 0);
}