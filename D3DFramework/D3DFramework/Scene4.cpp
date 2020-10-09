#include "stdafx.h"
#include "Scene4.h"
#include "Player4.h"
#include "Monster4.h"
#include "Cube.h"


void Scene4::OnLoaded()
{
	SceneStartTime = 0.f;
	MonsterRegenTime1 = 0.f;
	MonsterRegenTime2 = 0.f;
	Player4* p = (Player4*)ObjectManager::GetInstance()->CreateObject<Player4>();
	p->AddComponent<PKH::Cube>(L"Mesh");

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
		Cube* Comp = dynamic_cast<Cube*>(m->AddComponent<PKH::Cube>(L"Mesh"));
		Comp->Scene4ToDimension();
		//Monster4* m = (Monster4*)ObjectManager::GetInstance()->FindObject<Monster4>();
		m->SetCode(1);
		m->Ready();
	}
	if (MonsterRegenTime2 > 3.f) {
		MonsterRegenTime2 = 0.f;
		Monster4* m = (Monster4*)ObjectManager::GetInstance()->CreateObject<Monster4>();
		Cube* Comp = dynamic_cast<Cube*>(m->AddComponent<PKH::Cube>(L"Mesh"));
		Comp->Scene4ToDimension();
		//Monster4* m = (Monster4*)ObjectManager::GetInstance()->FindObject<Monster4>();
		m->SetCode(2);
		m->Ready();
	}
}
