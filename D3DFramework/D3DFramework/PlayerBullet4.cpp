#include "stdafx.h"
#include "PlayerBullet4.h"
#include "Monster4.h"
#include "Player4.h"
#include "Cube.h"

PKH::PlayerBullet4::PlayerBullet4()
{
}
PKH::PlayerBullet4::~PlayerBullet4()
{
}
void PKH::PlayerBullet4::Ready()
{
	switch (BulletCode)
	{
	case 1:
		transform->scale = { 1,1,1 };
		//TargetPlayer = ObjectManager::GetInstance()->FindObject<Player4>();
		//TargetPos = TargetPlayer->transform->position;
		//dir = TargetPos - transform->position;
		//Vector3::Normalize(&dir);
		moveSpeed = 4.f;
		break;
	case 2:
		transform->scale = { 1,1,1 };
		TargetMonster = ObjectManager::GetInstance()->FindObject<Monster4>();
		if (TargetMonster == nullptr) {
			BulletCode = 1;
			moveSpeed = 4.f;
			return;
		}
		moveSpeed = 6.f;
		break;
	default:
		break;
	}
}

void PKH::PlayerBullet4::Update()
{
	Player4* player = dynamic_cast<Player4*>(ObjectManager::GetInstance()->FindObject<Player4>());
	if (player->Get_DimensionChangeCheck())
		dynamic_cast<Cube*>(GetComponent(L"Mesh"))->Scene4ToDimension();
	if (transform->position.x < -4.5f || transform->position.x > 4.5f
		|| transform->position.y < -4.5f || transform->position.y > 4.5f
		|| transform->position.z < -4.5f || transform->position.z > 4.5f)
		isDead = true;

	if (1 == BulletCode) {
		//Move(TargetPos);

		transform->position.x += moveSpeed * TimeManager::DeltaTime();
		//transform->position.y += dir.y * moveSpeed * TimeManager::DeltaTime();
		//transform->position.z += dir.z * moveSpeed * TimeManager::DeltaTime();

	}
	else if (2 == BulletCode) {
		TargetMonster = ObjectManager::GetInstance()->FindObject<Monster4>();
		if (TargetMonster == nullptr) {
			Vector3 dir = TargetPos - transform->position;
			Vector3::Normalize(&dir);
			transform->position.x += dir.x * moveSpeed * TimeManager::DeltaTime();
			transform->position.y += dir.y * moveSpeed * TimeManager::DeltaTime();
			transform->position.z += dir.z * moveSpeed * TimeManager::DeltaTime();	
		}
		else {
			TargetPos = TargetMonster->transform->position;
			Move(TargetPos);
		}
		//Vector3::Normalize(&dir);

		///transform->position.x += moveSpeed * TimeManager::DeltaTime();
		//transform->position.y += dir.y * moveSpeed * TimeManager::DeltaTime();
		//transform->position.z += dir.z * moveSpeed * TimeManager::DeltaTime();
	}


	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

