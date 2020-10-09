#include "stdafx.h"
#include "Scene02.h"
#include "Player02.h"
#include "Enemy02.h"
#include "MyCollisionManager.h"
#include "Enum02.h"

void Scene02::OnLoaded()
{
	MyCollisionManager::GetInstance();

	Player02* player = new Player02;
	ObjectManager::AddObject(player);

	MyCollisionManager::GetInstance()->RegisterObject(OBJTAG::PLAYER, player);

	Enemy02* enemy = new Enemy02(Vector3(0.f, 10.f, 0.f), Vector3(0.f, -1.f, 0.f));
	ObjectManager::AddObject(enemy);

	MyCollisionManager::GetInstance()->RegisterObject(OBJTAG::ENEMY, enemy);
}

void Scene02::OnUnloaded()
{
	MyCollisionManager::DestroyInstance();
	ObjectManager::DestroyAll();
}

void Scene02::Update()
{
	MyCollisionManager::GetInstance()->Collide(OBJTAG::ENEMY, OBJTAG::PLAYER_BULLET);
}
