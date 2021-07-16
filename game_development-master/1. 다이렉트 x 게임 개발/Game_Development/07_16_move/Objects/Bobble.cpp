#include "stdafx.h"
#include "Bobble.h"



Bobble::Bobble(wstring textureFile, wstring shaderFile, D3DXVECTOR2 start, float angle, int color)
	: speed(1.5f), scale(50, 50), color(color)
{
	sprite = new Sprite(textureFile, shaderFile);

	position = start; 
	sprite->Position(position);
	sprite->Scale(scale);

	AngleToVelocity(angle, speed);
}

void Bobble::AngleToVelocity(float angle, float speed)
{
	this->angle = angle + 90.0f;
	velocity.x = cosf(Math::ToRadian(this->angle));
	velocity.y = sinf(Math::ToRadian(this->angle));
	velocity *= speed;
}

Bobble::~Bobble()
{
	SAFE_DELETE(sprite);
}

void Bobble::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	position += 0.1 * velocity;

	//반사벡터
	if (position.x <= 260 || position.x >= (Width - 260))
		velocity.x += 2 * (-velocity.x);

	//첫째줄 천장에 충돌시 멈춤
	if (position.y >= (Height - 85))
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	//첫째줄 정렬
	if (position.x >= 260 && position.x < 310 && position.y >= 510 && position.y < 515)
	{
		position.x = 280;
		position.y = 510;
	}
	else if (position.x >= 310 && position.x < 360 && position.y >= 510 && position.y < 515)
	{
		position.x = 330;
		position.y = 510;
	}
	else if (position.x >= 360 && position.x < 410 && position.y >= 510 && position.y < 515)
	{
		position.x = 380;
		position.y = 510;
	}
	else if (position.x >= 410 && position.x < 460 && position.y >= 510 && position.y < 515)
	{
		position.x = 430;
		position.y = 510;
	}
	else if (position.x >= 460 && position.x < 510 && position.y >= 510 && position.y < 515)
	{
		position.x = 480;
		position.y = 510;
	}
	else if (position.x >= 510 && position.x < 560 && 	position.y >= 510 && position.y < 515)
	{
		position.x = 530;
		position.y = 510;
	}

	sprite->Position(position);
	sprite->Update(V, P);
}

void Bobble::Render()
{
	sprite->Render();
}
