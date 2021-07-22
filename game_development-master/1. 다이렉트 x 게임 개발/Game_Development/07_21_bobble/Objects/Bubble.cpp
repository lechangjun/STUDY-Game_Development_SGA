#include "stdafx.h"
#include "Bubble.h"

Bubble::Bubble(wstring shaderFile, D3DXVECTOR2 start, float angle, float speed, int bubblecolor)
{
	
	wstring textureFile = L"";

	textureFile = L"../_Textures/PuzzleBobble/PuzzleBobble.png";

	color = bubblecolor; //5���� ��
	switch (color)
	{
	case 1: //�Ķ���
		bubble = new Sprite(textureFile, shaderFile, 11, 1187, 28, 1204);
		break;
	case 2: //������
		bubble = new Sprite(textureFile, shaderFile, 11, 1214, 28, 1231);
		break;
	case 3: //�����
		bubble = new Sprite(textureFile, shaderFile, 11, 1241, 28, 1257);
		break;
	case 4: //�ʷϻ�
		bubble = new Sprite(textureFile, shaderFile, 11, 1268, 28, 1284);
		break;
	case 5: //�����
		bubble = new Sprite(textureFile, shaderFile, 11, 1295, 28, 1312);
		break;
	}

	position = start;
	bubble->Position(position);
	bubble->Scale(52, 52);

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

	if (position.x - bubble->Scale().x / 2 <= 296 || position.x + bubble->Scale().x / 2 >= 714) //�� ���� ����� ��
	{
		velocity.x += 2.0f * -velocity.x;
	}
	//714 - 296 = 418
	//418 / 8 = 52.25(�� �ٿ� 8��)

	bubble->Position(position);
	bubble->Update(V, P);
}

void Bubble::Render()
{
	bubble->Render();
}

void Bubble::Position(float x, float y)
{
	Position(D3DXVECTOR2(x, y));
}

void Bubble::Position(D3DXVECTOR2 & vec)
{
	position = vec;
}

void Bubble::Velocity(D3DXVECTOR2 & vec)
{
	velocity = vec;
}

void Bubble::Location(float x, float y)
{
	Location(D3DXVECTOR2(x, y));
}

void Bubble::Location(D3DXVECTOR2 & vec)
{
	location = vec;
}
