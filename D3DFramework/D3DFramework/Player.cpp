#include "stdafx.h"
#include "Player.h"
#include "IComponent.h"
#include "Mesh.h"
#include "Missile.h"

using namespace PKH;

PKH::Player::Player()
{
	transform->position.y = -2;
	moveSpeed = 3.f;
}

PKH::Player::~Player()
{
}

void PKH::Player::Update()
{

	if (InputManager::GetKey('W'))
	{
		Move(transform->up);
		//Move(transform->position + Vector3::UP);
	}
	if (InputManager::GetKey('S'))
	{
		Move(Vector3::DOWN);
	}
	if (InputManager::GetKey('A'))
	{
		Move(Vector3::LEFT);
	}
	if (InputManager::GetKey('D'))
	{
		Move(Vector3::RIGHT);
	}
	if (InputManager::GetKey('Q'))
	{
		Move(Vector3::FORWARD);
	}
	if (InputManager::GetKey('E'))
	{
		Move(Vector3::BACK);
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


	if (InputManager::GetMouseLButton())
	{
		Attack();
	}
	if (InputManager::GetKey(VK_SPACE))
	{
		Attack();
	}

	// 딜레이 카운터
	attackTick += TimeManager::DeltaTime();
	if (attackTick > attackDelay)
	{
		attackTick = 0.f;
		attackFlag = true;
	}
		

	GameObject::Update();
}

void PKH::Player::Attack()
{
	if (attackFlag)
	{
		attackTick = 0.f;
		Missile* missile = (Missile*)ObjectManager::GetInstance()->CreateObject<Missile>();
		missile->transform->position = transform->position;

		Vector3 mousePos = Cursor::GetPosition();
		Vector3 mouseWorld = Camera::ScreenToWorldPoint(mousePos);
		//Vector3::Normalize(&mouseWorld);

		//missile->transform->LookAt(mouseWorld);
		missile->targetPos = mouseWorld;
		missile->moveSpeed = 10.f;
		attackFlag = false;
	}
}
