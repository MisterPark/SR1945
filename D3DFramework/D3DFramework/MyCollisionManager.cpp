#include "stdafx.h"
#include "MyCollisionManager.h"
#include "GameObject.h"

MyCollisionManager* MyCollisionManager::instance = nullptr;

using namespace PKH;

MyCollisionManager::MyCollisionManager()
{
}

MyCollisionManager::~MyCollisionManager()
{
	Release();
}

MyCollisionManager * MyCollisionManager::GetInstance()
{
	if (nullptr == instance) instance = new MyCollisionManager;

	return instance;
}

void MyCollisionManager::DestroyInstance()
{
	delete instance;
	instance = nullptr;
}

void MyCollisionManager::RegisterObject(OBJTAG tag, GameObject * obj)
{
	if (nullptr == obj) return;
	objList[tag].emplace_back(obj);
}

void MyCollisionManager::Collide(OBJTAG dst, OBJTAG src)
{
	auto dstIter = objList[dst].begin();
	auto srcIter = objList[src].begin();

	bool isCollide = false;

	for (; dstIter != objList[dst].end();)
	{
		for (; srcIter != objList[src].end();)
		{
			if (IsCollision((*dstIter)->transform, (*srcIter)->transform))
			{
				(*dstIter)->Die();
				(*srcIter)->Die();

				dstIter = objList[dst].erase(dstIter);
				srcIter = objList[src].erase(srcIter);

				isCollide = true;

				break;
			}
			++srcIter;
		}
		if(!isCollide) ++dstIter;
	}
}

void MyCollisionManager::Release()
{
	for (int i = 0; i < OBJTAG::END; ++i)
	{
		for (auto& iter : objList[i])
		{
			if (nullptr != iter)
			{
				delete iter;
				iter = nullptr;
			}
		}
		objList[i].clear();
	}
	objList->clear();
}

bool MyCollisionManager::IsCollision(Transform* dst, Transform* src)
{
	Vector3 target = dst->position - src->position;

	float dstRadius = dst->scale.z;
	float srcRadius = src->scale.z;

	float distance = sqrt(pow(target.x, 2) + pow(target.y, 2) + pow(target.z, 2));

	if (distance <= dstRadius + srcRadius)
		return true;

	return false;
}
