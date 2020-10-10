#include "stdafx.h"
#include "Dust03.h"
#include "Player03.h"
#include "Monster03.h"

PKH::Dust03::Dust03()
{
	transform->scale = { 1.f,1.f,1.f };
	moveSpeed = 10.f;
}



PKH::Dust03::~Dust03()
{
}

void PKH::Dust03::Update()
{

	
	transform->position.z -= moveSpeed*0.01f;

	if (transform->position.z < 1.f)
		Die();


	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

