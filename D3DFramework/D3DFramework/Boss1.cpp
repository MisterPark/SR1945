#include "stdafx.h"
#include "Boss1.h"
#include "Player.h"
#include "Missile.h"
#include "AirPlaneBodyMesh.h"
#include "AirPlaneWingMesh.h"
#include "AirPlaneTailMesh.h"

PKH::Boss1::Boss1()
{
	transform->position = { 0,100,100 };
	transform->scale = { 3.f,3.f,3.f };
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

PKH::Boss1::~Boss1()
{
	CollisionManager::DisregisterObject(this);
}

void PKH::Boss1::Update()
{
	switch (type)
	{
	case PKH::BossPatternType::PATTERN_01:
		Pattern1();
		break;
	case PKH::BossPatternType::PATTERN_02:
		Pattern2();
		break;
	case PKH::BossPatternType::PATTERN_03:
		Pattern3();
		break;
	default:
		break;
	}

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

void PKH::Boss1::Pattern1()
{
}

void PKH::Boss1::Pattern2()
{
}

void PKH::Boss1::Pattern3()
{
}

void PKH::Boss1::Attack()
{
}
