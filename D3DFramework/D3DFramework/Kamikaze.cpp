#include "stdafx.h"
#include "Kamikaze.h"
#include "AirPlaneBodyMesh.h"
#include "AirPlaneWingMesh.h"
#include "AirPlaneTailMesh.h"

using namespace PKH;

PKH::Kamikaze::Kamikaze()
{
	lifeTime = 10.f;
	transform->scale = { 1.0f,1.0f,1.0f };
	moveSpeed = 40.f;
	transform->eulerAngles.x = D3DXToRadian(90.f);
	isAlliance = false;

	Mesh* mesh = (Mesh*)AddComponent<PKH::AirPlaneBodyMesh>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(150, 50, 50));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneWingMesh>(L"Mesh2");
	mesh->SetColor(D3DCOLOR_XRGB(200, 100, 100));
	mesh = (Mesh*)AddComponent<PKH::AirPlaneTailMesh>(L"Mesh3");
	mesh->SetColor(D3DCOLOR_XRGB(200, 100, 100));

	CollisionManager::RegisterObject(this);
}

PKH::Kamikaze::~Kamikaze()
{

	CollisionManager::DisregisterObject(this);
}

void PKH::Kamikaze::Update()
{
	Missile::Update();
}

void PKH::Kamikaze::Die()
{
	Missile::Die();
}

void PKH::Kamikaze::OnCollision(GameObject* target)
{
	Missile::OnCollision(target);
}
