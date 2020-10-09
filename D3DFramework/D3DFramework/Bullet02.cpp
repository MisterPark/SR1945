#include "stdafx.h"
#include "Bullet02.h"
#include "Cube02.h"

Bullet02::Bullet02()
{
}

Bullet02::Bullet02(Vector3 pos, Vector3 scale, Vector3 look, bool isPlayer) :
	isPlayerType(isPlayer)
{
	transform->position = pos;
	transform->scale = scale;
	transform->look = look;

	Ready();
}

Bullet02::~Bullet02()
{
}

void Bullet02::Ready()
{
	moveSpeed = 10.f;

	if (isPlayerType)
	{
		IComponent* newCube = new Cube02(D3DCOLOR_XRGB(255, 255, 0));
		newCube->gameObject = this;
		components.emplace(L"Mesh", newCube);
	}
	else
	{
		IComponent* newCube = new Cube02(D3DCOLOR_XRGB(255, 0, 0));
		newCube->gameObject = this;
		components.emplace(L"Mesh", newCube);
	}
}

void Bullet02::Update()
{
	Move(transform->position + transform->look);

	for (auto& iter : components)
	{
		iter.second->Update();
	}
}
