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
			hp = 200;
			transform->scale = { 3.f,3.f,3.f };
			movePattern = 0.f;
		}
		if (!BossType)
		{
			transform->scale = { 1.f,1.f,1.f };
			if (xType)
			{
				delay = 1.f;
				moveSpeed = 10.f;
				Target = (Vector3{ 0,transform->position.y,transform->position.z }) - transform->position;
			}
			if (yType)
			{
				moveSpeed = 5.f;
				Target = (Vector3{transform->position.x,0.f,transform->position.z}) - transform->position;
			}
			if (!xType && !yType && !BossType)
			{
				Target = (Vector3{ transform->position.x,transform->position.y,0.f}) - transform->position;
			}
		}

	}
	if (!BossType)
	{
		if (!xType&&!yType)
		{
			GameObject* player = ObjectManager::GetInstance()->FindObject<Player03>();
			if (player != nullptr)
			{
				Vector3 dir = player->transform->position - transform->position;
				Vector3::Normalize(&dir);

				if (transform->position.x < 0.f)
					Move(Target);
				else
					Move(Target);

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

			if (transform->position.z < 1.f)
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


				Move(Target);



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

			if (transform->position.x > 9.f|| transform->position.x < -11.f)
			{
				Die();
			}
		}

		if (yType)
		{
			GameObject* player = ObjectManager::GetInstance()->FindObject<Player03>();
			if (player != nullptr)
			{
				Vector3 dir = player->transform->position - transform->position;
				Vector3::Normalize(&dir);
				

				Vector3 dir2 = player->transform->position - transform->position;
				Vector3::Normalize(&dir2);

				if (transform->position.x < 0.f)
					Move(Target);
				else
					Move(Target);

				float rotX = atan2f(dir.z, dir.y);
				float rotY = atan2f(dir.x, dir.z);
				float rotZ = atan2f(dir.y, dir.x);

				//if(transform->rotation.x < rotX)
				transform->rotation.x += rotX * TimeManager::DeltaTime();
				//if (transform->rotation.y < rotY)
				transform->rotation.y += rotY * TimeManager::DeltaTime();
				//if (transform->rotation.z < rotZ)
				transform->rotation.z += rotZ * TimeManager::DeltaTime();

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

			if (transform->position.y < -11.f|| transform->position.y > 11.f)
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
			
			
			if (BossSkill == 1)
			{
				Monster03* m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
				m->SetPosition(Vector3{ transform->position });
				m->AddComponent<PKH::Cube>(L"Mesh");
				
			}
			if (BossSkill == 10)
			{
				Monster03* m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
				m->SetPosition(Vector3{ transform->position - Vector3{1.f,0.f,0.f} });
				m->AddComponent<PKH::Cube>(L"Mesh");
				BossSkill = 0;
			}
			BossSkill++;
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

