#pragma once


class Bobble
{
public:
	Bobble(wstring textureFile, wstring shaderFile, D3DXVECTOR2 start, float angle, int color);
	~Bobble();

	void AngleToVelocity(float angle, float speed);

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
 
	//void Velocity(float x, float y);
	//void Velocity(D3DXVECTOR2& vec);
	//D3DXVECTOR2 Velocity() { return velocity; }

private:
	Sprite* sprite;

	D3DXVECTOR2 velocity;
	D3DXVECTOR2 position; 
	D3DXVECTOR2 scale;

	float speed;
	float angle;

	int color;
};
