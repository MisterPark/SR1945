#include "stdafx.h"
#include "ExplosionEffect.h"
#include "Rectangle.h"
#include "Plane.h"
#include "Player.h"

PKH::ExplosionEffect::ExplosionEffect()
{
	transform->scale = { 0.2f,0.2f,0.2f };
	Mesh* mesh = (Mesh*)AddComponent<PKH::Plane>(L"Mesh");
	mesh->SetColor(D3DCOLOR_XRGB(255, 0, 0));
	
}

PKH::ExplosionEffect::~ExplosionEffect()
{
}

void PKH::ExplosionEffect::Update()
{
	lifeTick += TimeManager::DeltaTime();
	if (lifeTick > lifeTime)
	{
		Die();
	}

	/*if(colorR >0)
		colorR--;*/
	
	if (colorG <255)
	{
		colorG++;
	}
	

	Mesh* mesh = (Mesh*)GetComponent(L"Mesh");
	
	mesh->SetColor(D3DCOLOR_XRGB(colorR, colorG, colorB));

	FaceTarget(Camera::GetPosition());

	GameObject::Update();
}
