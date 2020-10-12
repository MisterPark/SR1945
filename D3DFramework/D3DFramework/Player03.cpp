#include "stdafx.h"
#include "Player03.h"
#include "IComponent.h"
#include "Mesh.h"
#include "Bullet03.h"
#include "Cube.h"
#include "Monster03.h"
using namespace PKH;

PKH::Player03::Player03()
{
	transform->scale = { 1.f,1.f,1.f };
	moveSpeed = 3.f;
	hp = 10;
	
	Mesh* mesh = (Mesh*)AddComponent<PKH::Cube>(L"Mesh");
	mesh->SetColor(D3DCOLOR_RGBA(0, MyColor, MyColor, 0));
}

PKH::Player03::~Player03()
{
}

void PKH::Player03::Update()
{
	
	
		if (InputManager::GetKey(VK_UP))
		{
			if (transform->position.y < 3)
			{
				MoveToTarget(transform->position + Vector3::UP);
			}
		}
		if (InputManager::GetKey(VK_DOWN))
		{
			if (transform->position.y > -3)
			{
				MoveToTarget(transform->position + Vector3::DOWN);
			}
		}
		if (InputManager::GetKey(VK_LEFT))
		{
			if (transform->position.x > -4)
			{
				MoveToTarget(transform->position + Vector3::LEFT);
			}
		}
		if (InputManager::GetKey(VK_RIGHT))
		{
			if (transform->position.x < 4)
			{
				MoveToTarget(transform->position + Vector3::RIGHT);
			}
		}
		if (InputManager::GetKey('Z'))
		{
			if (transform->position.z < 1)
			{
				MoveToTarget(transform->position + Vector3::FORWARD);
			}
		}
		if (InputManager::GetKey('X'))
		{
			if (transform->position.z > -1)
			{
				MoveToTarget(transform->position + Vector3::BACK);
			}
		}
	
	if (InputManager::GetKey(VK_SPACE))
	{
		GameObject* monstercheck = ObjectManager::GetInstance()->FindObject<Monster03>();

		if (monstercheck)
		{
			tick += 5.f * TimeManager::DeltaTime();
			if (tick > delay)
			{
				Bullet03* b = (Bullet03*)ObjectManager::GetInstance()->CreateObject<Bullet03>();
				b->SetPosition(transform->position);
				b->MyBullet03 = true;
				tick = 0;
			}
		}
	}

	if (InputManager::GetKey(VK_NUMPAD7))
	{
		transform->eulerAngles.x += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD4))
	{
		transform->eulerAngles.x -= TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD8))
	{
		transform->eulerAngles.y += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD5))
	{
		transform->eulerAngles.y -= TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD9))
	{
		transform->eulerAngles.z += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD6))
	{
		transform->eulerAngles.z -= TimeManager::DeltaTime();
	}

	
	if (hp <= 0)
	{
		Die();
	}

	/*GameObject::Update();*/
}

void PKH::Player03::PostRender()
{
	Vector3 hpBar = {-4.f,-2.8f,0.f};


	Vector3 winPos = Camera::WorldToScreenPoint(hpBar);

	TCHAR buffer[32] = L"";

	wsprintf(buffer, L"HP : %d", hp);

	D2DRenderManager::DrawFont(buffer, winPos.x, winPos.y, D3DCOLOR_ARGB(MyColor, 0, MyColor, MyColor));
}
