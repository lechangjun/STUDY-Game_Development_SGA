#pragma once

class Bullet
{
public:
	Bullet(wstring shaderFile, wstring textureFile, D3DXVECTOR2 start, float angle, float speed);
	
	~Bullet();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

	void Reflection();
	
	int ColorCount() { return colorCount; }
	void ColorCount(int iColorCount) {};

	void BobbleIndex(int y, int x);
	int BobbleIndexX() {}
	int BobbleIndexY() {}
	
	void Destroy(int y int x);


private:
	D3DXVECTOR2 velocity;
	Sprite* sprite;

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	
	int bobbleIndexX;
	int bobbleIndexY;

	float bulletSpeed;
	float bulleAngle;
	float bulletRadian;
	bool bMove = false;
	int bobleColor;
	int colorCount = 0;
};