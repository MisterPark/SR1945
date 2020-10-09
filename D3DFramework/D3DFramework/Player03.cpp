#include "stdafx.h"
#include "Player03.h"
#include "IComponent.h"
#include "Mesh.h"
#include "Bullet.h"
#include "Cube.h"
using namespace PKH;

PKH::Player03::Player03()
{
	moveSpeed = 3.f;
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
				Move(transform->position + Vector3::UP);
			}
		}
		if (InputManager::GetKey(VK_DOWN))
		{
			if (transform->position.y > -3)
			{
				Move(transform->position + Vector3::DOWN);
			}
		}
		if (InputManager::GetKey(VK_LEFT))
		{
			if (transform->position.x > -4)
			{
				Move(transform->position + Vector3::LEFT);
			}
		}
		if (InputManager::GetKey(VK_RIGHT))
		{
			if (transform->position.x < 4)
			{
				Move(transform->position + Vector3::RIGHT);
			}
		}
		if (InputManager::GetKey('Z'))
		{
			if (transform->position.z < 1)
			{
				Move(transform->position + Vector3::FORWARD);
			}
		}
		if (InputManager::GetKey('X'))
		{
			if (transform->position.z > -1)
			{
				Move(transform->position + Vector3::BACK);
			}
		}
	
	if (InputManager::GetKey(VK_SPACE))
	{
		tick += 5.f*TimeManager::DeltaTime();
		if(tick>delay)
		{
			Bullet* b = (Bullet*)ObjectManager::GetInstance()->CreateObject<Bullet>();
			b->SetPosition(transform->position);
			b->MyBullet = true;
			b->AddComponent<PKH::Cube>(L"Mesh"); 
			tick = 0;
		}
		
	}

	if (InputManager::GetKey(VK_NUMPAD7))
	{
		transform->rotation.x += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD4))
	{
		transform->rotation.x -= TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD8))
	{
		transform->rotation.y += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD5))
	{
		transform->rotation.y -= TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD9))
	{
		transform->rotation.z += TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_NUMPAD6))
	{
		transform->rotation.z -= TimeManager::DeltaTime();
	}

	for (auto& comp : components)
	{
		comp.second->Update();
	}
}
