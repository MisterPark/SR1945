#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "Missile.h"
#include "Cube.h"


PKH::Monster::Monster()
{
	transform->position = { 100,0,100 };
	transform->scale = { 5,15,5 };
	moveSpeed = 30.f;
	
	dynamic_cast<Mesh*>(AddComponent<PKH::Cube>(L"Mesh"))->SetColor(D3DCOLOR_XRGB(50, 50, 50));

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


		transform->LookAt(*player->transform);
		

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

void PKH::Monster::PostRender()
{

	Vector3 pos = Camera::WorldToScreenPoint(transform->position);
	if (pos.z < 0.f)
	{
		return;
	}
	D2DRenderManager::DrawFont(L"¸ó½ºÅÍ", pos.x, pos.y, Color::Red);
}

