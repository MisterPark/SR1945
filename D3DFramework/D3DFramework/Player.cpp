#include "stdafx.h"
#include "Player.h"
#include "IComponent.h"
#include "Mesh.h"

using namespace PKH;

PKH::Player::Player()
{
	moveSpeed = 3.f;
}

PKH::Player::~Player()
{
}

void PKH::Player::Update()
{

	if (InputManager::GetKey(VK_UP))
	{
		Move(transform->position + Vector3::UP);
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		Move(transform->position + Vector3::DOWN);
	}
	if (InputManager::GetKey(VK_LEFT))
	{
		Move(transform->position + Vector3::LEFT);
	}
	if (InputManager::GetKey(VK_RIGHT))
	{
		Move(transform->position + Vector3::RIGHT);
	}
	if (InputManager::GetKey('Z'))
	{
		Move(transform->position + Vector3::FORWARD);
	}
	if (InputManager::GetKey('X'))
	{
		Move(transform->position + Vector3::BACK);
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
