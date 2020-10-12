#include "stdafx.h"
#include "Scene02.h"
#include "Player02.h"
#include "Enemy02.h"
#include "Boss02.h"
#include "MyCollisionManager.h"

void Scene02::OnLoaded()
{
	MyCollisionManager::GetInstance();

	Cursor::GetInstance()->isVisible = false;

	myPlayer = new Player02;
	ObjectManager::AddObject(myPlayer);
	MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::PLAYER, myPlayer);
}

void Scene02::OnUnloaded()
{
	MyCollisionManager::DestroyInstance();
	ObjectManager::DestroyAll();
}

void Scene02::Update()
{
	if (IsEndScene())
	{
		// ¾À ÀüÈ¯
		int i = 0;
	}

	SpawnByTime();

	MyCollisionManager::GetInstance()->Collide(MyCollisionManager::ENEMY, MyCollisionManager::PLAYER_BULLET);
	MyCollisionManager::GetInstance()->Collide2(MyCollisionManager::BOSS, MyCollisionManager::PLAYER_BULLET);
	MyCollisionManager::GetInstance()->Collide2(MyCollisionManager::PLAYER, MyCollisionManager::ENEMY_BULLET);
	MyCollisionManager::GetInstance()->CullingBullet(MyCollisionManager::ENEMY_BULLET);
	MyCollisionManager::GetInstance()->CullingBullet(MyCollisionManager::PLAYER_BULLET);
	MyCollisionManager::GetInstance()->CullingEnemy();
}

bool Scene02::IsEndScene()
{
	if (myPlayer->isDead) return true;

	if (isBossSpawn && myBoss->isDead) return true;

	return false;
}

void Scene02::SpawnByTime()
{
	if (!isBossSpawn)
	{
		playTime += TimeManager::DeltaTime();
		spawnTime += TimeManager::DeltaTime();
		spawnTime2 += TimeManager::DeltaTime();

		if (30.f < playTime)
		{
			SpawnEnemy01({ -1.5f, 5.f, 0.f });
			SpawnEnemy01({ 1.5f, 5.f, 0.f });

			SpawnEnemy02({ -2.5f, 1.5f, 5.f });
			SpawnEnemy02({ 2.5f, 1.5f, 5.f });

			SpawnBoss({ 0.f, 2.5f, 0.f });
		}

		if (4.f < spawnTime)
		{
			++spawnType;

			if (spawnType % 2)
			{
				SpawnEnemy01({ -1.5f, 5.f, 0.f });
				SpawnEnemy01({ 1.5f, 5.f, 0.f });
			}
			else
			{
				SpawnEnemy01({ 0.f, 5.f, 0.f });
				SpawnEnemy01({ 3.f, 5.f, 0.f });
				SpawnEnemy01({ -3.f, 5.f, 0.f });
			}

			spawnTime = 0.f;
		}
		
		if (8.f < spawnTime2)
		{
			++spawnType2;

			if (spawnType2 % 2)
			{
				SpawnEnemy02({ 0.f, 1.5f, 4.f });
			}
			else
			{
				SpawnEnemy02({ -2.5f, 1.5f, 4.f });
				SpawnEnemy02({ 2.5f, 1.5f, 4.f });
			}

			spawnTime2 = 0.f;
		}

	}
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
	if (!isBossSpawn)
	{
		myBoss = new Boss02(pos, look, myPlayer);
		ObjectManager::AddObject(myBoss);
		MyCollisionManager::GetInstance()->RegisterObject(MyCollisionManager::BOSS, myBoss);

		isBossSpawn = true;
	}
}
