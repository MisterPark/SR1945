#include "stdafx.h"
#include "Monster.h"
#include "Player.h"


PKH::Monster::Monster()
{
	//transform->scale = { 3,3,3 };
}

PKH::Monster::~Monster()
{
}

void PKH::Monster::Update()
{
	
	GameObject* player = ObjectManager::GetInstance()->FindObject<Player>();
	if (player != nullptr)
	{
		Vector3 dir = player->transform->position - transform->position;
		Vector3::Normalize(&dir);

		Move(player->transform->position);

		
		//float rotX = atan2f(dir.z, dir.y);
		//float rotY = atan2f(dir.x, dir.z);
		//float rotZ = atan2f(dir.y, dir.x);

		////if(transform->rotation.x < rotX)
		//	transform->rotation.x += rotX * TimeManager::DeltaTime();
		////if (transform->rotation.y < rotY)
		//	transform->rotation.y += rotY * TimeManager::DeltaTime();
		////if (transform->rotation.z < rotZ)
		//	transform->rotation.z += rotZ * TimeManager::DeltaTime();

		transform->LookAt(*player->transform);
		

	}
	

	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

