#include "stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "Missile.h"
#include "Cube.h"
#include "AirPlaneBodyMesh.h"
#include "AirPlaneWingMesh.h"
#include "AirPlaneTailMesh.h"


PKH::Monster::Monster()
{
	transform->position = dest1;
	transform->scale = { 0.5f,0.5f,0.5f };
	moveSpeed = 50.f;
	transform->eulerAngles.x = D3DXToRadian(90.f);
	
	Mesh* mesh = (Mesh*)AddComponent<PKH::AirPlaneBodyMesh>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(150, 50, 50));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneWingMesh>(L"Mesh2");
	mesh->SetColor(D3DCOLOR_XRGB(200, 100, 100));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneTailMesh>(L"Mesh3");
	mesh->SetColor(D3DCOLOR_XRGB(200, 100, 100));

	CollisionManager::RegisterObject(this);
}

PKH::Monster::~Monster()
{
}

void PKH::Monster::Update()
{
	
	switch (type)
	{
	case PKH::MonsterPatternType::PATTERN_01:
		Pattern1();
		break;
	case PKH::MonsterPatternType::PATTERN_02:
		Pattern2();
		break;
	case PKH::MonsterPatternType::PATTERN_03:
		Pattern3();
		break;
	default:
		break;
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
	Matrix view = Camera::GetViewMatrix();
	Vector3 viewPos;
	D3DXVec3TransformCoord(&viewPos, &transform->position, &view);
	if (viewPos.z < 0.f)
	{
		return;
	}

	Vector3 pos = Camera::WorldToScreenPoint(transform->position);
	
	D2DRenderManager::DrawFont(L"����", pos.x, pos.y, Color::Red);
}

void PKH::Monster::SetAirWay()
{
	Random::InitState();
	
	int rand;
	int value;

	dest1.x = Random::Range(-100.f, 300.f);
	dest1.y = Random::Range(-100.f, 300.f);
	dest1.z = Random::Range(-100.f, 300.f);
	
	dest2.x = Random::Range(-100.f, 300.f);
	dest2.y = Random::Range(-100.f, 300.f);
	dest2.z = Random::Range(-100.f, 300.f);

	dest3.x = Random::Range(-100.f, 300.f);
	dest3.y = Random::Range(-100.f, 300.f);
	dest3.z = Random::Range(-100.f, 300.f);

	transform->position = dest1;
}

void PKH::Monster::Pattern1()
{
	MoveToTarget(dest2);
	FaceTarget(dest2);

	if (Vector3::Distance(transform->position, dest2) < 5.f)
	{
		type = MonsterPatternType::PATTERN_02;
	}
}

void PKH::Monster::Pattern2()
{
	MoveToTarget(dest3);
	FaceTarget(dest3);
	if (Vector3::Distance(transform->position, dest3) < 5.f)
	{
		type = MonsterPatternType::PATTERN_03;
	}
}

void PKH::Monster::Pattern3()
{
	MoveToTarget(dest1);
	FaceTarget(dest1);
	if (Vector3::Distance(transform->position, dest1) < 5.f)
	{
		type = MonsterPatternType::PATTERN_01;
	}
}

void PKH::Monster::MoveToPlayer()
{
	GameObject* player = ObjectManager::GetInstance()->FindObject<Player>();
	if (player != nullptr)
	{
		Vector3 dir = player->transform->position - transform->position;
		Vector3::Normalize(&dir);

		//MoveToTarget(player->transform->position);


		transform->LookAt(*player->transform);


	}
}

