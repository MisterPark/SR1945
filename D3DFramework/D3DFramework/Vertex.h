#pragma once
class Vertex
{
public:
	Vertex(float _x, float _y, float _z, D3DCOLOR _color);
	float x;
	float y;
	float z;
	D3DCOLOR color;

	static const DWORD FVF; //�÷����� ���ؽ� ���� = �������� ���ؽ� ���� = Ŀ���� ���ؽ�
};
const DWORD Vertex::FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE;
