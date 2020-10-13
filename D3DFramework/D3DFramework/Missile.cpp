#include "stdafx.h"
#include "Missile.h"
#include "Cube.h"

PKH::Missile::Missile()
{
	transform->scale = { 2.f,5.f,2.f };
	Mesh* mesh = (Mesh*)AddComponent<PKH::Cube>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(255, 255, 0));
	CollisionManager::RegisterObject(this);
}

PKH::Missile::~Missile()
{
	CollisionManager::DisregisterObject(this);
}

void PKH::Missile::Update()
{
	if (target != nullptr)
	{
		// 유도탄
		
	}
	else
	{
		
	}

	Vector3 dir = targetPos - transform->position;
	Vector3::Normalize(&dir);

	Move(targetPos);
	transform->LookAt(transform->position+dir);

	// 범위 삭제
	//if (fabs(transform->position.x) < 10.f) return;
	//if (fabs(transform->position.y) < 30.f) return;
	//if (fabs(transform->position.z) < 30.f) return;

	if (lifeTick > lifeTime)
	{
		Die();
	}
	lifeTick += TimeManager::DeltaTime();

	GameObject::Update();
}

void PKH::Missile::Die()
{
	GameObject::Die();
}

void PKH::Missile::OnCollision(GameObject* target)
{
	if (target->isAlliance != isAlliance)
	{
		Die();
	}
}
