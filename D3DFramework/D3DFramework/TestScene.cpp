#include "stdafx.h"
#include "TestScene.h"
#include "Player.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Monster.h"
#include "SkyBox.h"

void TestScene::OnLoaded()
{
	SkyBox::Show();
	Camera::GetInstance()->SetPosition(Vector3(0, 1.f, -1.f));

	ObjectManager::GetInstance()->CreateObject<Player>();
	

	Monster* m = (Monster*)ObjectManager::GetInstance()->CreateObject<Monster>();
	m->AddComponent<PKH::Cube>(L"Mesh");


}

void TestScene::OnUnloaded()
{
	SkyBox::Hide();
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
