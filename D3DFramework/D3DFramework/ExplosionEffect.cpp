#include "stdafx.h"
#include "ExplosionEffect.h"
#include "Rectangle.h"
#include "Plane.h"
#include "Player.h"

PKH::ExplosionEffect::ExplosionEffect()
{
	Mesh* mesh = (Mesh*)AddComponent<PKH::Plane>(L"Mesh");
	
}

PKH::ExplosionEffect::~ExplosionEffect()
{
}

void PKH::ExplosionEffect::Update()
{
	Mesh* mesh = (Mesh*)GetComponent(L"Mesh");
	if (mesh == nullptr)
	{
		Die();
		
		return;
	}

	GameObject* player = ObjectManager::GetInstance()->FindObject<Player>();
	if (player == nullptr)return;

	FaceTarget(Camera::GetPosition());

	GameObject::Update();
}
