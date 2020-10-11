#include "stdafx.h"
#include "MonsterBullet4.h"
#include "Player4.h"
#include "Cube.h"
#include "CollisionManager4.h"
PKH::MonsterBullet4::MonsterBullet4()
{
}
PKH::MonsterBullet4::~MonsterBullet4()
{
}
void PKH::MonsterBullet4::Ready()
{
	switch (BulletCode)
	{
	case 1:
		transform->scale = { 0.5f, 0.5f, 0.5f };
		TargetPlayer = ObjectManager::GetInstance()->FindObject<Player4>();
		if (TargetPlayer == nullptr) {
			isDead = true;
			return;
		}
		TargetPos = TargetPlayer->transform->position;
		dir = TargetPos - transform->position;
		Vector3::Normalize(&dir);
		moveSpeed = 4.f;
		break;
	default:
		break;
	}
}

void PKH::MonsterBullet4::Update()
{
	if (transform->position.x < -5 || transform->position.x > 5
		|| transform->position.y < -5 || transform->position.y > 5
		|| transform->position.z < -5 || transform->position.z > 5) {
		isDead = true;
		CollisionManager4::FindObjectDelete(dynamic_cast<GameObject*>(this));
	}

	if (1 == BulletCode) {
		//Move(TargetPos);
		if (TargetPlayer != nullptr)
		{
		transform->position.x += dir.x * moveSpeed * TimeManager::DeltaTime();
		transform->position.y += dir.y * moveSpeed * TimeManager::DeltaTime();
		//transform->position.z += dir.z * moveSpeed * TimeManager::DeltaTime();

		//float rotX = atan2f(dir.z, dir.y);
		//float rotY = atan2f(dir.x, dir.z);
		//float rotZ = atan2f(dir.y, dir.x);

		//if(transform->rotation.x < rotX)
		//transform->rotation.x += rotX * TimeManager::DeltaTime();
		//if (transform->rotation.y < rotY)
		//transform->rotation.y += rotY * TimeManager::DeltaTime();
		//if (transform->rotation.z < rotZ)
		//transform->rotation.z += rotZ * TimeManager::DeltaTime();
		}
	}


	GameObject::Update();
}

