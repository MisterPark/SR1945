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

	if (InputManager::GetKey('W'))
	{
		Move(transform->position + transform->up);
		//Move(transform->position + Vector3::UP);
	}
	if (InputManager::GetKey('S'))
	{
		Move(transform->position + Vector3::DOWN);
	}
	if (InputManager::GetKey('A'))
	{
		Move(transform->position + Vector3::LEFT);
	}
	if (InputManager::GetKey('D'))
	{
		Move(transform->position + Vector3::RIGHT);
	}
	if (InputManager::GetKey('Q'))
	{
		Move(transform->position + Vector3::FORWARD);
	}
	if (InputManager::GetKey('E'))
	{
		Move(transform->position + Vector3::BACK);
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

	for (auto& comp : components)
	{
		comp.second->Update();
	}
}
