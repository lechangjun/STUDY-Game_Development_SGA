#pragma once

class Bubble
{
public:
	Bubble(wstring shaderFile, D3DXVECTOR2 start, float angle, float speed);
	~Bubble();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

private:
	D3DXVECTOR2 velocity;
	Sprite* bubble;

	D3DXVECTOR2 position;
};