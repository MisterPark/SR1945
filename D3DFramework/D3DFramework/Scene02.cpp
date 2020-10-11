#include "stdafx.h"
#include "Scene02.h"
#include "Player02.h"
#include "Enemy02.h"
#include "Boss02.h"
#include "MyCollisionManager.h"

void Scene02::OnLoaded()
{
	MyCollisionManager::GetInstance();

	myPlayer = new Player02;
	ObjectManager::AddObject(myPlayer);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::PLAYER, myPlayer);

	SpawnEnemy01(Vector3(0.f, 2.5f, 0.f), Vector3(0.f, -1.f, 0.f));
	SpawnEnemy02(Vector3(-3.f, 2.5f, 5.f), Vector3(0.f, -1.f, 0.f));
	SpawnBoss({ 0.f, 2.5f, 0.f }, { 0.f, -1.f, 0.f });
}

void Scene02::OnUnloaded()
{
	MyCollisionManager::DestroyInstance();
	ObjectManager::DestroyAll();
}

void Scene02::Update()
{
	MyCollisionManager::GetInstance()->Collide(MyCollisionManager::ENEMY, MyCollisionManager::PLAYER_BULLET);
	MyCollisionManager::GetInstance()->Collide2(MyCollisionManager::BOSS, MyCollisionManager::PLAYER_BULLET);
	MyCollisionManager::GetInstance()->Collide2(MyCollisionManager::PLAYER, MyCollisionManager::ENEMY_BULLET);
	MyCollisionManager::GetInstance()->CullingBullet(MyCollisionManager::ENEMY_BULLET);
	MyCollisionManager::GetInstance()->CullingBullet(MyCollisionManager::PLAYER_BULLET);
}

void Scene02::SpawnEnemy01(Vector3 pos, Vector3 look)
{
	Enemy02* enemy = new Enemy02(pos, look);
	ObjectManager::AddObject(enemy);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::ENEMY, enemy);
}

void Scene02::SpawnEnemy02(Vector3 pos, Vector3 look)
{
	Enemy02* enemy = new Enemy02(pos, look, 2, myPlayer);
	ObjectManager::AddObject(enemy);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::ENEMY, enemy);
}

void Scene02::SpawnBoss(Vector3 pos, Vector3 look)
{
	Boss02* enemy = new Boss02(pos, look, myPlayer);
	ObjectManager::AddObject(enemy);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::BOSS, enemy);
}
