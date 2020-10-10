#include "stdafx.h"
#include "Scene02.h"
#include "Player02.h"
#include "Enemy02.h"
#include "MyCollisionManager.h"

void Scene02::OnLoaded()
{
	MyCollisionManager::GetInstance();

	Player02* player = new Player02;
	ObjectManager::AddObject(player);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::PLAYER, player);

	Enemy02* enemy = new Enemy02(Vector3(-3.f, 2.5f, 5.f), Vector3(0.f, -1.f, 0.f), 2, player);
	ObjectManager::AddObject(enemy);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::ENEMY, enemy);

	enemy = new Enemy02(Vector3(0.f, 2.5f, 5.f), Vector3(0.f, -1.f, 0.f), 2, player);
	ObjectManager::AddObject(enemy);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::ENEMY, enemy);

	enemy = new Enemy02(Vector3(3.f, 2.5f, 5.f), Vector3(0.f, -1.f, 0.f), 2, player);
	ObjectManager::AddObject(enemy);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::ENEMY, enemy);
}

void Scene02::OnUnloaded()
{
	MyCollisionManager::DestroyInstance();
	ObjectManager::DestroyAll();
}

void Scene02::Update()
{
	MyCollisionManager::GetInstance()->Collide(MyCollisionManager::ENEMY, MyCollisionManager::PLAYER_BULLET);
	MyCollisionManager::GetInstance()->CullingBullet(MyCollisionManager::ENEMY_BULLET);
	MyCollisionManager::GetInstance()->CullingBullet(MyCollisionManager::PLAYER_BULLET);
}
