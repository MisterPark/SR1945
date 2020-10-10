#include "stdafx.h"
#include "Scene4.h"
#include "Player4.h"
#include "Monster4.h"
#include "Cube.h"
#include "CollisionManager4.h"
#include "Random_Manager4.h"


void Scene4::OnLoaded()
{
	SceneStartTime = 0.f;
	MonsterRegenTime1 = 0.f;
	MonsterRegenTime2 = 0.f;
	Player4* p = (Player4*)ObjectManager::GetInstance()->CreateObject<Player4>();
	CollisionManager4::GetInstance()->RegisterObject(CollisionManager4::PLAYER, p);
	p->AddComponent<PKH::Cube>(L"Mesh");
	Random_Manager::Get_Instance()->Ready_Random();
	//Monster4* m = (Monster4*)ObjectManager::GetInstance()->CreateObject<Monster4>();
	//m->AddComponent<PKH::Cube>(L"Mesh");

}

void Scene4::OnUnloaded()
{
	ObjectManager::DestroyAll();
}

void Scene4::Update()
{
	SceneStartTime += TimeManager::DeltaTime();
	MonsterRegenTime1 += TimeManager::DeltaTime();
	MonsterRegenTime2 += TimeManager::DeltaTime();
	LARGE_INTEGER AccCount, PerCount;
	QueryPerformanceFrequency(&PerCount);
	PerCount.QuadPart *= 0.1f;
	QueryPerformanceCounter(&AccCount);
	if (MonsterRegenTime1 > 2.f) {
		MonsterRegenTime1 = 0.f;
		Monster4* m = (Monster4*)ObjectManager::GetInstance()->CreateObject<Monster4>();
		CollisionManager4::GetInstance()->RegisterObject(CollisionManager4::MONSTER, m);
		Cube* Comp = dynamic_cast<Cube*>(m->AddComponent<PKH::Cube>(L"Mesh"));
		//Monster4* m = (Monster4*)ObjectManager::GetInstance()->FindObject<Monster4>();
		m->SetCode(1);
		m->Ready();
	}
	if (MonsterRegenTime2 > 3.f) {
		MonsterRegenTime2 = 0.f;
		Monster4* m = (Monster4*)ObjectManager::GetInstance()->CreateObject<Monster4>();
		CollisionManager4::GetInstance()->RegisterObject(CollisionManager4::MONSTER, m);
		Cube* Comp = dynamic_cast<Cube*>(m->AddComponent<PKH::Cube>(L"Mesh"));
		//Monster4* m = (Monster4*)ObjectManager::GetInstance()->FindObject<Monster4>();
		m->SetCode(2);
		m->Ready();
	}
	CollisionManager4::GetInstance()->Update();
}
