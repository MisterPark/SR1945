#include "stdafx.h"
#include "Monster03.h"
#include "Player03.h"
#include "Bullet03.h"
#include "Cube.h"
#include "ObjectManager.h"
PKH::Monster03::Monster03()
{
	transform->scale = { 1.f,1.f,1.f};
	hp = 3;
}



PKH::Monster03::~Monster03()
{
}

void PKH::Monster03::Update()
{
	if (!isSetting)
	{
		isSetting = true;
		if (BossType)
		{
			delay = 0.5f;
			hp = 20;
			transform->scale = { 3.f,3.f,3.f };
			movePattern = 0.f;
		}
		if (!BossType)
		{
			transform->scale = { 1.f,1.f,1.f };
			if (xType)
			{
				moveSpeed = 10.f;
			}

		}

	}
	if (!BossType)
	{
		if (!xType)
		{
			GameObject* player = ObjectManager::GetInstance()->FindObject<Player03>();
			if (player != nullptr)
			{
				Vector3 dir = player->transform->position - transform->position;
				Vector3::Normalize(&dir);

				if (transform->position.x < 0.f)
					Move(Vector3{ -3,0,-3.f });
				else
					Move(Vector3{ 3,0,-3.f });

				float rotX = atan2f(dir.z, dir.y);
				float rotY = atan2f(dir.x, dir.z);
				float rotZ = atan2f(dir.y, dir.x);

				//if(transform->rotation.x < rotX)
				transform->eulerAngles.x += rotX * TimeManager::DeltaTime();
				//if (transform->rotation.y < rotY)
				transform->eulerAngles.y += rotY * TimeManager::DeltaTime();
				//if (transform->rotation.z < rotZ)
				transform->eulerAngles.z += rotZ * TimeManager::DeltaTime();

				if (transform->position.z > 2)
				{
					tick += TimeManager::DeltaTime();
					if (tick > delay)
					{
						Bullet03* b = (Bullet03*)ObjectManager::GetInstance()->CreateObject<Bullet03>();
						b->SetPosition(transform->position);
						b->AddComponent<PKH::Cube>(L"Mesh");
						tick = 0;
					}
				}
			}

			if (transform->position.z < -1.f)
			{
				Die();
			}
		}

		if (xType)
		{
			
			GameObject* player = ObjectManager::GetInstance()->FindObject<Player03>();
			if (player != nullptr)
			{
				Vector3 dir = player->transform->position - transform->position;
				Vector3::Normalize(&dir);


				Move(Vector3{ 20.f,0.f,5.f });



				float rotX = atan2f(dir.z, dir.y);
				float rotY = atan2f(dir.x, dir.z);
				float rotZ = atan2f(dir.y, dir.x);

				//if(transform->rotation.x < rotX)
				transform->eulerAngles.x += rotX * TimeManager::DeltaTime();
				//if (transform->rotation.y < rotY)
				transform->eulerAngles.y += rotY * TimeManager::DeltaTime();
				//if (transform->rotation.z < rotZ)
				transform->eulerAngles.z += rotZ * TimeManager::DeltaTime();

				if (transform->position.z > 2)
				{
					tick += TimeManager::DeltaTime();
					if (tick > delay)
					{
						Bullet03* b = (Bullet03*)ObjectManager::GetInstance()->CreateObject<Bullet03>();
						b->SetPosition(transform->position);
						b->AddComponent<PKH::Cube>(L"Mesh");
						tick = 0;
					}
				}
			}

			if (transform->position.x > 18.f)
			{
				Die();
			}
		}
	}

	if (BossType)
	{
		transform->eulerAngles.z += TimeManager::DeltaTime();


		if (movePattern)
		{
			transform->position.x += TimeManager::DeltaTime();
		}

		if (transform->position.x > 5)
		{
			moveSpeed *= -1.f;
		}

		tick += TimeManager::DeltaTime();
		if (tick > delay)
		{
			Bullet03* b = (Bullet03*)ObjectManager::GetInstance()->CreateObject<Bullet03>();
			b->SetPosition(transform->position);
			b->AddComponent<PKH::Cube>(L"Mesh");
			tick = 0;
		}
	}
		if (hp <= 0)
		{
			Die();
		}
	
	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

