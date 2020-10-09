#include "stdafx.h"
#include "Scene03.h"
#include "Player03.h"
#include "Monster03.h"
#include "Monster03_2.h"
#include "Monster03_Boss.h"
#include "Triangle.h"
#include "Rectangle.h"
#include "Cube.h"

void Scene03::OnLoaded()
{
	Player03* p = (Player03*)ObjectManager::GetInstance()->CreateObject<Player03>();
	
	p->AddComponent<PKH::Cube>(L"Mesh");

	Monster03* m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
	m->SetPosition(Vector3{ -6.f,0.f,5.f });
	m->AddComponent<PKH::Cube>(L"Mesh");
	
	m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
	m->SetPosition(Vector3{ -3.f,0.f,8.f });
	m->AddComponent<PKH::Cube>(L"Mesh");

	m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
	m->SetPosition(Vector3{ 0.f,5.f,11.f });
	m->AddComponent<PKH::Cube>(L"Mesh");

	m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
	m->SetPosition(Vector3{ 3.f,0.f,14.f });
	m->AddComponent<PKH::Cube>(L"Mesh");

	m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
	m->SetPosition(Vector3{ 6.f,10.f,17.f });
	m->AddComponent<PKH::Cube>(L"Mesh");


	//Monster03_2* m = (Monster03_2*)ObjectManager::GetInstance()->CreateObject<Monster03_2>();
	//m->SetPosition(Vector3{ 0.f,0.f,5.f });
	//m->AddComponent<PKH::Cube>(L"Mesh");
	//


}

void Scene03::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void Scene03::Update()
{
	GameObject* monstercheck = ObjectManager::GetInstance()->FindObject<Monster03>();
	if (!monstercheck)
	{
		Monster03* m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
		m->SetPosition(Vector3{ -6.f,0.f,5.f });
		m->AddComponent<PKH::Cube>(L"Mesh");

		m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
		m->SetPosition(Vector3{ -3.f,0.f,8.f });
		m->AddComponent<PKH::Cube>(L"Mesh");

		m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
		m->SetPosition(Vector3{ 0.f,5.f,11.f });
		m->AddComponent<PKH::Cube>(L"Mesh");

		m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
		m->SetPosition(Vector3{ 3.f,0.f,14.f });
		m->AddComponent<PKH::Cube>(L"Mesh");

		m = (Monster03*)ObjectManager::GetInstance()->CreateObject<Monster03>();
		m->SetPosition(Vector3{ 6.f,10.f,17.f });
		m->AddComponent<PKH::Cube>(L"Mesh");

	}
}
