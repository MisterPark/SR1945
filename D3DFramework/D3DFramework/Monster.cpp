#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "Missile.h"


PKH::Monster::Monster()
{
	transform->position = { 0,0,2 };
	transform->scale = { 5,5,15 };
	CollisionManager::RegisterObject(this);
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

		//MoveToTarget(player->transform->position);


		//transform->LookAt(*player->transform);
		

	}
	

	GameObject::Update();
}

void PKH::Monster::OnCollision(GameObject* target)
{
	if (dynamic_cast<Player*>(target))
	{

	}
	else if (dynamic_cast<Missile*>(target))
	{
		Missile* ms = (Missile*)target;
		if (ms->isAlliance)
		{
			Die();
		}
	}
}

void PKH::Monster::Die()
{
	GameObject::Die();
	CollisionManager::DisregisterObject(this);
}

