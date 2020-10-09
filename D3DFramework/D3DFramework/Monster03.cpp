#include "stdafx.h"
#include "Monster03.h"
#include "Player03.h"
#include "Bullet.h"
#include "Cube.h"
#include "ObjectManager.h"
PKH::Monster03::Monster03()
{
	transform->scale = { 1,1,1 };

}



PKH::Monster03::~Monster03()
{
}

void PKH::Monster03::Update()
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
			transform->rotation.x += rotX * TimeManager::DeltaTime();
			//if (transform->rotation.y < rotY)
			transform->rotation.y += rotY * TimeManager::DeltaTime();
			//if (transform->rotation.z < rotZ)
			transform->rotation.z += rotZ * TimeManager::DeltaTime();

			if (transform->position.z > 2)
			{
				tick+=TimeManager::DeltaTime();
				if (tick >delay)
				{
					Bullet* b = (Bullet*)ObjectManager::GetInstance()->CreateObject<Bullet>();
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



	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

