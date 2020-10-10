#include "stdafx.h"
#include "Player4.h"
#include "PlayerBullet4.h"
#include "IComponent.h"
#include "Mesh.h"
#include "Cube.h"

using namespace PKH;

PKH::Player4::Player4()
{
	moveSpeed = 3.f;
	Key_C = false;
	Key_V = false;
	Key_T = false;
	Dimension2D = false;
	DimensionChangeCheck = false;
}

PKH::Player4::~Player4()
{
}

void PKH::Player4::Update()
{
	if (DimensionChangeCheck)
		dynamic_cast<Cube*>(GetComponent(L"Mesh"))->Scene4ToDimension();
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
	if (InputManager::GetKey('C'))
	{
		if (!Key_C) {
			CreateBullet(1);
			Key_C = true;
		}
	}
	else {
		Key_C = false;
	}
	if (InputManager::GetKey('V'))
	{
		if (!Key_V) {
			CreateBullet(2);
			Key_V = true;
		}
	}
	else {
		Key_V = false;
	}
	DimensionChangeCheck = false;
	if (InputManager::GetKey('T'))
	{
		if (!Key_T) {
			Key_T = true;
			DimensionChangeCheck = true;
			if (Dimension2D)
				Dimension2D = false;
			else
				Dimension2D = true;
		}
	}
	else {
		Key_T = false;
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

void PKH::Player4::CreateBullet(int Code) {
	PlayerBullet4* b = (PlayerBullet4*)ObjectManager::GetInstance()->CreateObject<PlayerBullet4>();
	Cube* Comp = dynamic_cast<Cube*>(b->AddComponent<PKH::Cube>(L"Mesh"));
	Comp->Scene4ToDimension();
	b->SetCode(Code);
	*(b->GetTransform()->Get_Pos()) = transform->position;
	b->Ready();
}