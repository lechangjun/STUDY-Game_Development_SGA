#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(wstring shaderFile, D3DXVECTOR2 start, float angle, float speed)
{
	sprite = new Sprite(Textures + L"Bullets.png", shaderFile, 173, 155, 183, 167);

	position = start;
	sprite->Position(position);

	float radian = Math::ToRadian(angle);
	velocity.x = cosf(radian);
	velocity.y = sinf(radian);
	velocity *= speed;
}

Bullet::Bullet(wstring shaderFile, wstring textureFile, D3DXVECTOR2 start, float angle, float speed)
{
}

Bullet::~Bullet()
{
	SAFE_DELETE(sprite);
}

void Bullet::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	position += velocity;

	if (position.x <= 0 || position.x >= Width)
	{
		velocity.x += 2.0f * -velocity.x;
	}
	else if (position.y <= 0 || position.y >= Height)
	{
		velocity.y += 2.0f* -velocity.y;
	}

	sprite->Position(position);
	sprite->Update(V, P);
}

void Bullet::Render()
{
	sprite->Render();
}

void Bullet::Reflection()
{
}

void Bullet::BobbleIndex(int y, int x)
{
}

void Bullet::Destroy(int y int x)
{
}
