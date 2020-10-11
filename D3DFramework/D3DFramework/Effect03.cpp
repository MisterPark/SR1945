#include "stdafx.h"
#include "Effect03.h"
#include "Player03.h"
#include "Monster03.h"
#include "Cube.h"

PKH::Effect03::Effect03()
{
	
	transform->scale = { 1.f,1.f,1.f };
	moveSpeed = 10.f;
}



PKH::Effect03::~Effect03()
{
}

void PKH::Effect03::Update()
{

	if (PlayerHit)
	{
		GameObject* player = ObjectManager::GetInstance()->FindObject<Player03>();
		if (nullptr != player)
		{
			int color = dynamic_cast<Player03*>(player)->MyColor;
			Mesh* mesh = (Mesh*)AddComponent<PKH::Cube>(L"Mesh");
			mesh->SetColor(D3DCOLOR_XRGB(0, color, color));
		}
	}
	if (!PlayerHit)
	{

		GameObject* monster = ObjectManager::GetInstance()->FindObject<Monster03>();
		if (nullptr != monster)
		{
			int color = dynamic_cast<Monster03*>(monster)->MyColor;
			Mesh* mesh = (Mesh*)AddComponent<PKH::Cube>(L"Mesh");
			mesh->SetColor(D3DCOLOR_XRGB(color, color, color));
		}
	}
	transform->scale -= Vector3{ 0.01f,0.01f,0.01f };
	if (effectDir == 0)
	{
		transform->position -= Vector3{0.01f,0.01f, 0.01f };
	}
	if (effectDir == 1)
	{
		transform->position -= Vector3{ -0.01f,0.01f, 0.01f };
	}
	if (effectDir == 2)
	{
		transform->position -= Vector3{ 0.01f,-0.01f, 0.01f };
	}
	if (effectDir == 3)
	{
		transform->position -= Vector3{ -0.01f,-0.01f, 0.01f };
	}
	tick += TimeManager::DeltaTime();
	if (tick > delay)
	{
		Die();
	}


	
	GameObject::Update();
}

