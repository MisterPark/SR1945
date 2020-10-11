#include "stdafx.h"
#include "PlayerBullet4.h"
#include "Monster4.h"
#include "Player4.h"
#include "Cube.h"
#include "Random_Manager4.h"

PKH::PlayerBullet4::PlayerBullet4()
{
	BulletPatternTime = 0.f;
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
	if (transform->position.x < -4.5f || transform->position.x > 4.5f
		|| transform->position.y < -4.5f || transform->position.y > 4.5f
		|| transform->position.z < -4.5f || transform->position.z > 4.5f) {
		//isDead = true;
		//CollisionManager4::FindObjectDelete4(dynamic_cast<GameObject*>(this));
	}

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
			//transform->position.z += dir.z * moveSpeed * TimeManager::DeltaTime();
			transform->position.z = 0.f;
			
		}
		else {
			TargetPos = TargetMonster->transform->position;
			//Move(TargetPos);
			Vector3 dir = TargetPos - transform->position;
			if (abs(dir.x) + abs(dir.y) > 1.f) {
				Vector3::Normalize(&dir);
				if (BulletPattern == 0) {
					if(dir.x < 0)
						transform->position.x -= moveSpeed * TimeManager::DeltaTime();
					else
						transform->position.x += moveSpeed * TimeManager::DeltaTime();
				}
				else if (BulletPattern == 1) {
					if (dir.y < 0)
						transform->position.y -= moveSpeed * TimeManager::DeltaTime();
					else
						transform->position.y += moveSpeed * TimeManager::DeltaTime();
				}
				//transform->position.z = 0.f;
				BulletPatternTime -= TimeManager::DeltaTime();
				if (BulletPatternTime < 0) {
					BulletPatternTime = 0.1f;
					if (Random_Manager::Random() % 2 == 0) {
						if(abs(dir.x) > 0.5f)
							BulletPattern = 0;
						else
							BulletPattern = 1;
					}
					else {
						if (abs(dir.y) > 0.5f)
							BulletPattern = 1;
						else
							BulletPattern = 0;
					}
				}
			}
			else {
				Vector3::Normalize(&dir);
				transform->position.x += dir.x * moveSpeed * TimeManager::DeltaTime();
				transform->position.y += dir.y * moveSpeed * TimeManager::DeltaTime();
			}
		}
		//Vector3::Normalize(&dir);

		///transform->position.x += moveSpeed * TimeManager::DeltaTime();
		//transform->position.y += dir.y * moveSpeed * TimeManager::DeltaTime();
		//transform->position.z += dir.z * moveSpeed * TimeManager::DeltaTime();
	}


	GameObject::Update();
}

