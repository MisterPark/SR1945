#include "stdafx.h"
#include "TestScene.h"
#include "Player.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Monster.h"
#include "SkyBox.h"
#include "ExplosionEffect.h"

void TestScene::OnLoaded()
{
	SkyBox::Show();
	Cursor::Hide();
	Cursor::GetInstance()->isVisible = true;
	Camera::GetInstance()->SetPosition(Vector3(0, 1.f, -1.f));

	ObjectManager::GetInstance()->CreateObject<Player>();
	
	for (int i = 0; i < 10; i++)
	{
		Monster* m = (Monster*)ObjectManager::GetInstance()->CreateObject<Monster>();
		m->dest1.x = Random::Range(-100.f, 300.f);
		m->dest1.y = Random::Range(-100.f, 300.f);
		m->dest1.z = Random::Range(-100.f, 300.f);
		
		m->dest2.x = Random::Range(-100.f, 300.f);
		m->dest2.y = Random::Range(-100.f, 300.f);
		m->dest2.z = Random::Range(-100.f, 300.f);
		
		m->dest3.x = Random::Range(-100.f, 300.f);
		m->dest3.y = Random::Range(-100.f, 300.f);
		m->dest3.z = Random::Range(-100.f, 300.f);
		
		m->transform->position = m->dest1;
		//m->SetAirWay();
	}
	
	GameObject* effect = ObjectManager::GetInstance()->CreateObject<ExplosionEffect>();
	effect->transform->position = { 0,0,2 };


}

void TestScene::OnUnloaded()
{
	Cursor::Show();
	Cursor::GetInstance()->isVisible = false;
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
