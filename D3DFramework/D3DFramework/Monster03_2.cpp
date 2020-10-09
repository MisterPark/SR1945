#include "stdafx.h"
#include "Monster03_2.h"
#include "Player03.h"


PKH::Monster03_2::Monster03_2()
{
	transform->scale = { 1,1,1 };

}



PKH::Monster03_2::~Monster03_2()
{
}

void PKH::Monster03_2::Update()
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


	}


	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

