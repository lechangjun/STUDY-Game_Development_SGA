#include "stdafx.h"
#include "Objects/Bullet.h"

Bullet::Bullet(wstring shaderFile, D3DXVECTOR2 start, float angle, float speed)
{
	sprite = new Sprite(Textures + L"blueBead.png", shaderFile);
	position = start; 
	sprite->Position(position);
	float radian = Math::ToRadian(angle);
	velocity.x = cosf(radian);
	velocity.y = sinf(radian);

	velocity *= speed;
	

}

Bullet::~Bullet()
{
	SAFE_DELETE(sprite);
}

void Bullet::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	position += velocity;

	if (position.x < 548 - 55 * 4 + 55/2 || position.x > 548 + 55 * 4 - 55/2)
	{
		velocity.x += -2 * velocity.x;

		
	}

	if (position.y < 0 )
	{
		velocity.y += -2 * velocity.y;
	}
	else if (position.y > Height - 80 - 55/2)
	{
		velocity.y = 0;
		velocity.x = 0;
	}




	sprite->Position(position);
	sprite->Update(V, P);
}

void Bullet::Render()
{
	sprite->Render();
}

void Bullet::Position(float x, float y)
{
	Position(D3DXVECTOR2(x, y));
}

void Bullet::Position(D3DXVECTOR2 & vec)
{
	position = vec;
}

