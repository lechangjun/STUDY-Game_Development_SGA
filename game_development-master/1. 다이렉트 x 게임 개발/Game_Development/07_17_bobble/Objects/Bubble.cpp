#include "stdafx.h"
#include "Bubble.h"

Bubble::Bubble(wstring shaderFile, D3DXVECTOR2 start, float angle, float speed)
{
	wstring textureFile = L"";

	textureFile = L"../_Textures/PuzzleBobble/PuzzleBobble.png";
	bubble = new Sprite(textureFile, shaderFile, 11, 1187, 28, 1204);

	position = start;
	bubble->Position(position);
	bubble->Scale(40, 40);

	float radian = Math::ToRadian(angle);
	velocity.x = cosf(radian);
	velocity.y = sinf(radian);
	velocity *= speed;
}

Bubble::~Bubble()
{
	SAFE_DELETE(bubble);
}

void Bubble::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	position += velocity;

	if (position.x - bubble->Scale().x / 2 <= 296 || position.x + bubble->Scale().x / 2 >= 714) //¿· º®¿¡ ´ê¾ÒÀ» ¶§
	{
		velocity.x += 2.0f * -velocity.x;
	}
	if (position.y >= Height - 100)//À§¿¡ º®¿¡ ´ê¾ÒÀ»¶§
	{
		velocity = D3DXVECTOR2(0, 0);
	}

	bubble->Position(position);
	bubble->Update(V, P);
}

void Bubble::Render()
{
	bubble->Render();
}
