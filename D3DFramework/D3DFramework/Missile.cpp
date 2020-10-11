#include "stdafx.h"
#include "Missile.h"
#include "Cube.h"

PKH::Missile::Missile()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Cube>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(255, 255, 0));
}

PKH::Missile::~Missile()
{
}

void PKH::Missile::Update()
{
	if (target != nullptr)
	{
		// À¯µµÅº
		
	}
	else
	{
		MoveToTarget(targetPos);
	}
}
