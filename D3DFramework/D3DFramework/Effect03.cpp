#include "stdafx.h"
#include "Effect03.h"
#include "Player03.h"
#include "Monster03.h"

PKH::Effect03::Effect03()
{
	transform->scale = { 1.f,1.f,1.f };
	moveSpeed = 10.f;
}



PKH::Effect03::~Effect03()
{
}

void PKH::Effect03::Update()
{

	transform->scale -= Vector3{ 0.01f,0.01f,0.01f };
	transform->position.z -= 0.01f;
	tick += TimeManager::DeltaTime();
	if (tick > delay)
	{
		Die();
	}


	
	GameObject::Update();
}

