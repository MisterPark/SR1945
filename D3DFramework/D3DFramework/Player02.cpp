#include "stdafx.h"
#include "Player02.h"
#include "Cube02.h"
#include "Bullet02.h"
#include "MyCollisionManager.h"
#include "Enum02.h"

Player02::Player02()
{
	IComponent* mesh = new Cube02(D3DCOLOR_XRGB(255, 255, 255));
	mesh->gameObject = this;
	components.emplace(L"Mesh", mesh);

	moveSpeed = 3.f;
}

Player02::~Player02()
{
}

void Player02::Update()
{
	if (!canAttack)
	{
		coolTime -= TimeManager::DeltaTime();

		if (0.f > coolTime) canAttack = true;
	}

	if (InputManager::GetKey(VK_UP))
	{
		Move(transform->position + Vector3::UP);
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		Move(transform->position + Vector3::DOWN);
	}
	if (InputManager::GetKey(VK_LEFT))
	{
		Move(transform->position + Vector3::LEFT);
	}
	if (InputManager::GetKey(VK_RIGHT))
	{
		Move(transform->position + Vector3::RIGHT);
	}
	if (InputManager::GetKey(VK_SPACE))
	{
		Attack();
	}

	for (auto& iter : components)
	{
		iter.second->Update();
	}
}

void Player02::Attack()
{
	if (canAttack)
	{
		Bullet02* newBullet = new Bullet02(transform->position, Vector3(0.2f, 0.2f, 0.2f), transform->up);
		ObjectManager::AddObject(newBullet);

		MyCollisionManager::GetInstance()->RegisterObject(OBJTAG::PLAYER_BULLET, newBullet);

		canAttack = false;
		coolTime = 0.3f;
	}
}