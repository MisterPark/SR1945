#include "stdafx.h"
#include "Enemy02.h"
#include "Bullet02.h"
#include "Cube02.h"
#include "MyCollisionManager.h"
#include "Enum02.h"

Enemy02::Enemy02()
{
}

Enemy02::Enemy02(Vector3 pos, Vector3 look, int type) :
	type(type)
{
	transform->position = pos;
	transform->look = look;

	moveSpeed = 1.f;

	Ready();
}

Enemy02::~Enemy02()
{
}

void Enemy02::Ready()
{
	IComponent* mesh = new Cube02(D3DCOLOR_XRGB(0, 255, 0));
	mesh->gameObject = this;
	components.emplace(L"Mesh", mesh);
}

void Enemy02::Update()
{
	if (0 == type)
	{
		if (canAttack) Attack();
		else
		{
			coolTime -= TimeManager::DeltaTime();

			if (0.f > coolTime) canAttack = true;
		}

		Move(transform->position + transform->look);
	}
	else if (1 == type)
	{

	}
}

void Enemy02::Attack()
{
	Bullet02* newBullet = new Bullet02(transform->position, Vector3(0.2f, 0.2f, 0.2f), Vector3(0.f, -1.f, 0.f), false);

	ObjectManager::AddObject(newBullet);

	MyCollisionManager::GetInstance()->RegisterObject(OBJTAG::ENEMY_BULLET, newBullet);

	canAttack = false;

	coolTime = 1.f;
}
