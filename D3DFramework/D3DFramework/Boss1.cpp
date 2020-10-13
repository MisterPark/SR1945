#include "stdafx.h"
#include "Boss1.h"
#include "Player.h"
#include "Missile.h"
#include "AirPlaneBodyMesh.h"
#include "AirPlaneWingMesh.h"
#include "AirPlaneTailMesh.h"
#include "Kamikaze.h"

PKH::Boss1::Boss1()
{
	transform->position = { 0,0,-400 };
	transform->scale = { 10.f,10.f,10.f };
	moveSpeed = 50.f;
	isAlliance = false;
	transform->eulerAngles.x = D3DXToRadian(90.f);
	Mesh* mesh = (Mesh*)AddComponent<PKH::AirPlaneBodyMesh>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(150, 50, 50));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneWingMesh>(L"Mesh2");
	mesh->SetColor(D3DCOLOR_XRGB(200, 100, 100));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneTailMesh>(L"Mesh3");
	mesh->SetColor(D3DCOLOR_XRGB(200, 100, 100));

	CollisionManager::RegisterObject(this);
}

PKH::Boss1::~Boss1()
{
	CollisionManager::DisregisterObject(this);
}

void PKH::Boss1::Update()
{
	switch (type)
	{
	case PKH::BossPatternType::PATTERN_00:
		Pattern0();
		break;
	case PKH::BossPatternType::PATTERN_01:
		Pattern1();
		break;
	case PKH::BossPatternType::PATTERN_02:
		//Pattern1();
		Pattern2();
		break;
	case PKH::BossPatternType::PATTERN_03:
		//Pattern1();
		Pattern2();
		Pattern3();
		break;
	default:
		break;
	}


	attackTick += TimeManager::DeltaTime();
	attack2Tick += TimeManager::DeltaTime();
	attack3Tick += TimeManager::DeltaTime();

	if (attackTick > attackDelay)
	{
		attackFlag = true;
	}
	if (attack2Tick > attack2Delay)
	{
		attack2Flag = true;
	}
	if (attack3Tick > attack3Delay)
	{
		attack3Flag = true;
	}

	PhaseUpdate();

	GameObject::Update();
}

void PKH::Boss1::OnCollision(GameObject* target)
{
	if (dynamic_cast<Player*>(target))
	{

	}
	else if (dynamic_cast<Missile*>(target))
	{
		Missile* ms = (Missile*)target;
		if (ms->isAlliance)
		{
			hp--;
			if (hp < 1)
				Die();
		}
	}
}

void PKH::Boss1::Die()
{
	Player* player = (Player*)ObjectManager::GetInstance()->FindObject<Player>();
	player->isGameOver = true;
	GameObject::Die();
}

void PKH::Boss1::PostRender()
{
	Matrix view = Camera::GetViewMatrix();
	Vector3 viewPos;
	D3DXVec3TransformCoord(&viewPos, &transform->position, &view);
	if (viewPos.z < 0.f)
	{
		return;
	}

	Vector3 pos = Camera::WorldToScreenPoint(transform->position);

	WCHAR wstr[64];
	wsprintf(wstr, L"HP :%d/100", hp);
	D2DRenderManager::DrawFont(wstr, pos.x, pos.y + 10, Color::Red);
}

void PKH::Boss1::Pattern0()
{
	MoveToTarget(Vector3::ZERO);

	if (Vector3::Distance(transform->position, Vector3::ZERO) < 10.f)
	{
		type = BossPatternType::PATTERN_01;
	}
}

void PKH::Boss1::Pattern1()
{
	
	if (attackFlag)
	{
		attackFlag = false;
		attackTick = 0.f;

		GameObject* player = ObjectManager::GetInstance()->FindObject<Player>();
		if (player == nullptr) return;

		Missile* missile = (Missile*)ObjectManager::GetInstance()->CreateObject<Missile>();
		missile->transform->position = transform->position;
		missile->target = player;
		missile->transform->scale = { 5,8,5 };
		missile->moveSpeed = 100.f;
		missile->isAlliance = false;

	}
	

}

void PKH::Boss1::Pattern2()
{
	if (attack2Flag)
	{
		attack2Flag = false;
		attack2Tick = 0.f;

		GameObject* player = ObjectManager::GetInstance()->FindObject<Player>();
		if (player == nullptr) return;

		Kamikaze* kami = (Kamikaze*)ObjectManager::GetInstance()->CreateObject<Kamikaze>();
		kami->transform->position = transform->position;
		kami->target = player;
		kami->isAlliance = false;
	}
}

void PKH::Boss1::Pattern3()
{
	if (attack3Flag)
	{
		attack3Flag = false;
		attack3Tick = 0.f;

		float radius = 30.f;
		Vector3 startPos = transform->position + (transform->right * radius);
		Vector3 pos2;

		for (int i = 0; i < 20; i++) // Y축 회전
		{
			float theta2 = D3DXToRadian(18.f * i);
			pos2.x = (startPos.x * cosf(theta2)) - (startPos.y * sinf(theta2));
			pos2.y = startPos.y;
			pos2.z = (startPos.x * sinf(theta2)) + (startPos.y * cosf(theta2)) + startPos.z;


			Vector3 pos;

			for (int j = 0; j < 20; j++) // Z축 회전
			{
				float theta = D3DXToRadian(18.f * j);
				pos.x = (pos2.x * cosf(theta)) - (pos2.y * sinf(theta));
				pos.y = (pos2.x * sinf(theta)) + (pos2.y * cosf(theta));
				pos.z = pos2.z;

				Missile* missile = (Missile*)ObjectManager::GetInstance()->CreateObject<Missile>();
				missile->transform->position = pos;
				missile->transform->scale = { 20,20,20 };
				
				missile->isAlliance = false;
				missile->moveSpeed = 100.f;
				missile->lifeTime = 10.f; // 이거 뺴야함 디버그용

				Vector3 dir = pos - transform->position;
				Vector3::Normalize(&dir);
				missile->targetPos = dir * 1000.f;
			}
		}

	}
	
}

void PKH::Boss1::PhaseUpdate()
{
	if (hp < 200)
	{
		type = BossPatternType::PATTERN_02;
	}
	if (hp < 100)
	{
		type = BossPatternType::PATTERN_03;
	}
}

