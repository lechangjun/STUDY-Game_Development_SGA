#include "stdafx.h"
#include "Device.h"
#include "Objects/Background.h"
#include "Objects/Bullet.h"

Background* bg;
vector<Sprite *> sprites;
vector<Bullet *> bullets;

D3DXVECTOR2 position;

int puzzleposition[7][8] = {};
bool bpuzzle[7][8] = {};

void InitScene()
{
	bg = new Background(L"../_Shaders/008_Sprite.fx");

	wstring shaderFile = L"../_Shaders/008_Sprite.fx";

	Sprite* Launcher;
	Sprite* Arrow;
	//Bullet* Bead;

	//Launcher = new Sprite(L"../_Textures/puzzle.png", shaderFile, 7, 260, 89, 304 ,0);
	/*Launcher->Position(515, 50);
	sprites.push_back(Launcher);
	Launcher->Scale(200, 100);
	position = D3DXVECTOR2(510, 80);*/

	Launcher = new Sprite(L"../_Textures/puzzle.png", shaderFile, 278, 1107, 385, 1148, 0);
	Launcher->Position(545, 82);
	sprites.push_back(Launcher);
	Launcher->Scale(392, 164);
	position = D3DXVECTOR2(Width / 2, 80);

	//Arrow = new Sprite(L"../_Textures/puzzle.png", shaderFile, 9, 16, 31, 80, 0);
	/*Arrow->Position(510, 80);
	sprites.push_back(Arrow);
	Arrow->Scale(50, 120);*/
	Arrow = new Sprite(L"../_Textures/puzzle.png", shaderFile, 21, 791, 61, 851, 0);

	//Arrow->Position(555, 80);
	sprites.push_back(Arrow);
	Arrow->Scale(80, 108);
	//Arrow->Rotation(70.0f);

	//Bead = new Bullet(L"../_Textures/blueBead.png",shaderFile,0,0,0.5f);
	Bullet* bullet = new Bullet(Shaders + L"008_Sprite.fx", position, sprites[1]->Rotation() + 90, 0.0f);
	bullets.push_back(bullet);
	
}

void DestroyScene()
{
	for (Bullet* bullet :bullets)
		SAFE_DELETE(bullet)

	for (Sprite* sprite : sprites)
		SAFE_DELETE(sprite);

	SAFE_DELETE(bg);
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

	bg->Update(V, P);

	for (Sprite* sprite : sprites)
	{
		//sprite->ViewProjection();
		sprite->Update(V, P);
	}
	
	

	//bullet키
	if (Key->Press(VK_LEFT))
	{
		sprites[1]->Rotation(sprites[1]->Rotation() + 0.01f);

		if (sprites[1]->Rotation() >= 70.0f)
		{
			sprites[1]->Rotation(70.0f);
		}
	}
	
	else if (Key->Press(VK_RIGHT))
	{
		sprites[1]->Rotation(sprites[1]->Rotation() - 0.01f);

		if (sprites[1]->Rotation() <= -70.0f)
		{
			sprites[1]->Rotation(-70.0f);
		}
	}

	/*if (Key->Press(VK_UP))
		position.y += 200.0f * Timer->Elapsed();
	else if (Key->Press(VK_DOWN))
		position.y -= 200.0f * Timer->Elapsed();*/

	sprites[1]->Position(position);//화살 회전 적용




	if (Key->Down(VK_SPACE))
	{
		wstring file = Shaders + L"008_Sprite.fx";

		//float angle = sprites[1]->Rotation();
		//float speed = Math::Random(0.05f, 0.05f);

		Bullet* bullet = new Bullet(file, position, sprites[1]->Rotation()+90, 0.07f);
		bullets.push_back(bullet);
		
		

	}
//328 , 768 /2 = Width / 2
	//
	
	
	

	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i]->Position().y >= Height - 80 - 55 / 2)//1번째 줄
		{
			if (bullets[i]->Position().x > Width / 2 - 55 * 4 && bullets[i]->Position().x < Width / 2 - 55 * 3)
			{
				bullets[i]->Position(Width / 2 - 55 * 4 + 55 / 2, Height - 110);
				
				bpuzzle[0][0] = true;	
			}
			
			else if (bullets[i]->Position().x > Width / 2 - 55 * 3 && bullets[i]->Position().x < Width / 2 - 55 * 2)
			{
				bullets[i]->Position(Width / 2 - 55 * 3 + 55 / 2, Height - 110);

				bpuzzle[0][1] = true;
			}
			else if (bullets[i]->Position().x > Width / 2 - 55 * 2 && bullets[i]->Position().x < Width / 2 - 55 * 1)
			{
				bullets[i]->Position(Width / 2 - 55 * 2 + 55 / 2, Height - 110);

				bpuzzle[0][2] = true;
			}
			else if (bullets[i]->Position().x > Width / 2 - 55 * 1 && bullets[i]->Position().x < Width / 2 - 55 * 0)
			{
				bullets[i]->Position(Width / 2 - 55 * 1 + 55 / 2, Height - 110);

				bpuzzle[0][3] = true;
			}
			else if (bullets[i]->Position().x > Width / 2 - 55 * 0 && bullets[i]->Position().x < Width / 2 + 55 * 1)
			{
				bullets[i]->Position(Width / 2 - 55 * 0 + 55 / 2, Height - 110);
				bpuzzle[0][4] = true;
			}
			else if (bullets[i]->Position().x > Width / 2 + 55 * 1 && bullets[i]->Position().x < Width / 2 + 55 * 2)
			{
				bullets[i]->Position(Width / 2 + 55 * 1 + 55 / 2, Height - 110);
				bpuzzle[0][5] = true;
			}
			else if (bullets[i]->Position().x > Width / 2 + 55 * 2 && bullets[i]->Position().x < Width / 2 + 55 * 3)
			{
				bullets[i]->Position(Width / 2 + 55 * 2 + 55 / 2, Height - 110);
				bpuzzle[0][6] = true;
			}
			else if (bullets[i]->Position().x > Width / 2 + 55 * 3 && bullets[i]->Position().x < Width / 2 + 55 * 4)
			{
				bullets[i]->Position(Width / 2 + 55 * 3 + 55 / 2, Height - 110);
				bpuzzle[0][7] = true;
			}
		}

		else if (bullets[i]->Position().y >= Height - 80 - 55 * 1 - 55 / 2)//2번째 줄
		{
			if(bpuzzle[0][0] == true)
			{ 
				if (bullets[i]->Position().x > Width / 2 - 55 * 4 + 55 / 2 && bullets[i]->Position().x < Width / 2 - 55 * 3 + 55 / 2)
				{
					bullets[i]->Position(Width / 2 - 55 * 3, Height - 80 - 55 * 1 - 55 / 2);
					bpuzzle[1][0] = true;
				}
			}
			else if (bpuzzle[0][1] == true)
			{
				if (bullets[i]->Position().x > Width / 2 - 55 * 4 + 55 / 2 && bullets[i]->Position().x < Width / 2 - 55 * 3 + 55 / 2)
				{
					bullets[i]->Position(Width / 2 - 55 * 3, Height - 80 - 55 * 1 - 55 / 2);
					bpuzzle[1][0] = true;
				}
				else if (bullets[i]->Position().x > Width / 2 - 55 * 3 + 55 / 2 && bullets[i]->Position().x < Width / 2 - 55 * 2 + 55 / 2)
				{
					bullets[i]->Position(Width / 2 - 55 * 2, Height - 80 - 55 * 1 - 55 / 2);
					bpuzzle[1][1] = true;
				}
			}
			else if (bpuzzle[0][2] == true)
			{
				if (bullets[i]->Position().x > Width / 2 - 55 * 3 + 55 / 2 && bullets[i]->Position().x < Width / 2 - 55 * 2 + 55 / 2)
				{
					bullets[i]->Position(Width / 2 - 55 * 2, Height - 80 - 55 * 1 - 55 / 2);
					bpuzzle[1][1] = true;
				}
				else if (bullets[i]->Position().x > Width / 2 - 55 * 2 + 55 / 2 && bullets[i]->Position().x < Width / 2 - 55 * 1 + 55 / 2)
				{
					bullets[i]->Position(Width / 2 - 55 * 1, Height - 80 - 55 * 1 - 55 / 2);
					bpuzzle[1][2] = true;
				}
			}

		}

		/*else if (puzzleposition[0][0])//2
		{
			if (bullets[i]->Position().x > Width / 2 - 55 * 4 + 55 / 2 && bullets[i]->Position().x < Width / 2 - 55 * 3 + 55 / 2 && puzzleposition[0][0])
			{
				bullets[i]->Position(Width / 2 - 55 * 3 , Height - 110);
				
			}
			else if (bullets[i]->Position().x > Width / 2 - 55 * 3 && bullets[i]->Position().x < Width / 2 - 55 * 2)
			{
				bullets[i]->Position(Width / 2 - 55 * 3 + 55 / 2, Height - 110);
			}
			else if (bullets[i]->Position().x > Width / 2 - 55 * 2 && bullets[i]->Position().x < Width / 2 - 55 * 1)
			{
				bullets[i]->Position(Width / 2 - 55 * 2 + 55 / 2, Height - 110);
			}
			else if (bullets[i]->Position().x > Width / 2 - 55 * 1 && bullets[i]->Position().x < Width / 2 - 55 * 0)
			{
				bullets[i]->Position(Width / 2 - 55 * 1 + 55 / 2, Height - 110);
			}
			else if (bullets[i]->Position().x > Width / 2 - 55 * 0 && bullets[i]->Position().x < Width / 2 + 55 * 1)
			{
				bullets[i]->Position(Width / 2 - 55 * 0 + 55 / 2, Height - 110);
			}
			else if (bullets[i]->Position().x > Width / 2 + 55 * 1 && bullets[i]->Position().x < Width / 2 + 55 * 2)
			{
				bullets[i]->Position(Width / 2 + 55 * 1 + 55 / 2, Height - 110);
			}
			else if (bullets[i]->Position().x > Width / 2 + 55 * 2 && bullets[i]->Position().x < Width / 2 + 55 * 3)
			{
				bullets[i]->Position(Width / 2 + 55 * 2 + 55 / 2, Height - 110);
			}
			else if (bullets[i]->Position().x > Width / 2 + 55 * 3 && bullets[i]->Position().x < Width / 2 + 55 * 4)
			{
				bullets[i]->Position(Width / 2 + 55 * 3 + 55 / 2, Height - 110);
			}
		}*/

		//else if (bullets[i]->Position().y >= Height - 80 -55*1 - 55 / 2)//3
		//{
		//	if (bullets[i]->Position().x > Width / 2 - 55 * 4 && bullets[i]->Position().x < Width / 2 - 55 * 3)
		//	{
		//		bullets[i]->Position(Width / 2 - 55 * 4 + 55 / 2, Height - 110);
		//	}
		//	else if (bullets[i]->Position().x > Width / 2 - 55 * 3 && bullets[i]->Position().x < Width / 2 - 55 * 2)
		//	{
		//		bullets[i]->Position(Width / 2 - 55 * 3 + 55 / 2, Height - 110);
		//	}
		//	else if (bullets[i]->Position().x > Width / 2 - 55 * 2 && bullets[i]->Position().x < Width / 2 - 55 * 1)
		//	{
		//		bullets[i]->Position(Width / 2 - 55 * 2 + 55 / 2, Height - 110);
		//	}
		//	else if (bullets[i]->Position().x > Width / 2 - 55 * 1 && bullets[i]->Position().x < Width / 2 - 55 * 0)
		//	{
		//		bullets[i]->Position(Width / 2 - 55 * 1 + 55 / 2, Height - 110);
		//	}
		//	else if (bullets[i]->Position().x > Width / 2 - 55 * 0 && bullets[i]->Position().x < Width / 2 + 55 * 1)
		//	{
		//		bullets[i]->Position(Width / 2 - 55 * 0 + 55 / 2, Height - 110);
		//	}
		//	else if (bullets[i]->Position().x > Width / 2 + 55 * 1 && bullets[i]->Position().x < Width / 2 + 55 * 2)
		//	{
		//		bullets[i]->Position(Width / 2 + 55 * 1 + 55 / 2, Height - 110);
		//	}
		//	else if (bullets[i]->Position().x > Width / 2 + 55 * 2 && bullets[i]->Position().x < Width / 2 + 55 * 3)
		//	{
		//		bullets[i]->Position(Width / 2 + 55 * 2 + 55 / 2, Height - 110);
		//	}
		//	else if (bullets[i]->Position().x > Width / 2 + 55 * 3 && bullets[i]->Position().x < Width / 2 + 55 * 4)
		//	{
		//		bullets[i]->Position(Width / 2 + 55 * 3 + 55 / 2, Height - 110);
		//	}
		//}
	}




	for (Bullet* bullet : bullets)
		bullet->Update(V, P);

}

//Culling 면을 버림 3D단계
//Clipping 정점을 버림 2D 단계

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(0, 0, 0, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		bg->Render();

		for (Bullet* bullet : bullets)
		{
			bullet->Render();
		}

		for (Sprite* sprite : sprites)
		{
			sprite->Render();
		}

		
	}
	ImGui::Render();
	SwapChain->Present(0, 0);

}

//IA > VS > RS > PS > OM > BB > 
//	  WVP 3D>2D		RTV/DSV