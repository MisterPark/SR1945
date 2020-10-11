#include "stdafx.h"
#include "TestScene.h"
#include "Player.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Monster.h"

void TestScene::OnLoaded()
{
	Camera::GetInstance()->SetPosition(Vector3(0, 0, -3));

	Player*  p = (Player*)ObjectManager::GetInstance()->CreateObject<Player>();
	Mesh* mesh = (Mesh*)p->AddComponent<PKH::Cube>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(100, 100, 100));

	Monster* m = (Monster*)ObjectManager::GetInstance()->CreateObject<Monster>();
	m->AddComponent<PKH::Cube>(L"Mesh");


}

void TestScene::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void TestScene::Update()
{
	if (InputManager::GetKey(VK_UP))
	{
		Camera::GetInstance()->transform->position.x += 5.f * TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_DOWN))
	{
		Camera::GetInstance()->transform->position.x -= 5.f *TimeManager::DeltaTime();
	}
	if (InputManager::GetKey(VK_LEFT))
	{

	}
	if (InputManager::GetKey(VK_RIGHT))
	{

	}
}
