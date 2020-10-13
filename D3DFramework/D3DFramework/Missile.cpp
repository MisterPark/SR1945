#include "stdafx.h"
#include "Missile.h"
#include "Cube.h"
#include "ExplosionEffect.h"

PKH::Missile::Missile()
{
	transform->eulerAngles.x = D3DXToRadian(90.f);
	transform->scale = { 2.f,5.f,2.f };
	moveSpeed = 200.f;
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
		if (target->isDead)
		{
			Die();
		}
		// À¯µµÅº

		Vector3 dir = target->transform->position - transform->position;
		Vector3::Normalize(&dir);
		transform->LookAt(transform->position + dir);
		Move(transform->up);

		GameObject* effect = ObjectManager::GetInstance()->CreateObject<ExplosionEffect>();
		effect->SetPosition(transform->position - (transform->up * 3));
	}
	else
	{
		Vector3 dir = targetPos - transform->position;
		Vector3::Normalize(&dir);

		Move(targetPos);
		transform->LookAt(transform->position + dir);
	}

	

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
	if (target == nullptr) return;
	if (dynamic_cast<Missile*>(target)) return;
	if (target->isAlliance != isAlliance)
	{
		Die();
	}
}
