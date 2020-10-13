#include "stdafx.h"
#include "TestScene.h"
#include "Player.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"
#include "Monster.h"
#include "SkyBox.h"
#include "ExplosionEffect.h"
#include "Boss1.h"
#include "GameOverScene.h"


void TestScene::OnLoaded()
{
	SkyBox::Show();
	Cursor::Hide();
	Cursor::GetInstance()->isVisible = true;
	Camera::GetInstance()->SetPosition(Vector3(0, 1.f, -1.f));

	p = (Player*)ObjectManager::GetInstance()->CreateObject<Player>();
	
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
	}
	

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
	if (p != nullptr)
	{
		if (p->isGameOver)
		{
			SceneManager::LoadScene<GameOverScene>();
		}
	}


	time += TimeManager::DeltaTime();
	if (time > bossTime)
	{
		if (bossFlag)
		{
			return;
		}
		Boss1* boss = (Boss1*)ObjectManager::GetInstance()->CreateObject<Boss1>();
		bossFlag = true;
	}

	
}
