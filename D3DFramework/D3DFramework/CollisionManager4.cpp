#include "stdafx.h"
#include "CollisionManager4.h"
#include "Player4.h"
#include "PlayerBullet4.h"
#include "Monster4.h"
#include "MonsterBullet4.h"

using namespace PKH;

PKH::CollisionManager4* PKH::CollisionManager4::pInstance = nullptr;

PKH::CollisionManager4::CollisionManager4()
{
}

PKH::CollisionManager4::~CollisionManager4()
{
}

PKH::CollisionManager4* PKH::CollisionManager4::GetInstance()
{
	if (nullptr == pInstance)
	{
		pInstance = new CollisionManager4;
	}
	return pInstance;
}

void PKH::CollisionManager4::Destroy()
{
	if (pInstance)
	{
		delete pInstance;
		pInstance = nullptr;
	}
}

void PKH::CollisionManager4::CollisionSphere(GameObject* rDstObj, GameObject* rSrcObj)
{
	if (CheckSphere(rDstObj, rSrcObj)) {
		rDstObj->OnCollision(rSrcObj);
		rSrcObj->OnCollision(rDstObj);
	}
}

bool PKH::CollisionManager4::CheckSphere(GameObject* rDstObj, GameObject* rSrcObj)
{
	float fRadiusSum = (rDstObj->transform->scale.x * 0.25f) + (rSrcObj->transform->scale.x * 0.25f);
	float fX = rDstObj->transform->position.x - rSrcObj->transform->position.x;
	float fY = rDstObj->transform->position.y - rSrcObj->transform->position.y;
	float fZ = rDstObj->transform->position.z - rSrcObj->transform->position.z;
	float fDist = sqrtf(fX * fX + fY * fY + fZ * fZ);
	return fDist < fRadiusSum;

	//Vector3 target = rDstObj->transform->position - rSrcObj->transform->position;
	//float dstRadius = rDstObj->transform->scale.z;
	//float srcRadius = rSrcObj->transform->scale.z;

	//float distance = sqrt(pow(target.x, 2) + pow(target.y, 2) + pow(target.z, 2));

	//return distance <= dstRadius + srcRadius;
}

void PKH::CollisionManager4::Update()
{
	//for (auto src : pInstance->objectList)
	//{
	//	for (auto dest : pInstance->objectList)
	//	{
	//		if (src == dest)
	//			continue;

	//		if (CollisionManager4::IsCollided(src, dest))
	//		{
	//			src->OnCollision(dest);
	//		}

	//	}
	//}
	MonsterToPBulletCollision();
}

void PKH::CollisionManager4::RegisterObject(OBJTAG _ObjTag, GameObject* _pObj)
{
	if (FindObject(_pObj))
	{
		return;
	}
	pInstance->objectList[_ObjTag].emplace_back(_pObj);
}

void PKH::CollisionManager4::DisregisterObject(GameObject* _pObj)
{
	if (_pObj == nullptr)
		return;

	for (int i = 0; i < OBJTAG::TAG_END; i++) {
		for (auto iter = pInstance->objectList[i].begin(); iter != pInstance->objectList[i].end(); ++iter)
		{
			if ((*iter) != _pObj) continue;

			pInstance->objectList[i].erase(iter);
			return;
		}
	}
}

bool PKH::CollisionManager4::FindObject(GameObject* _pObj)
{
	if (_pObj == nullptr)
		return false;

	for (int i = 0; i < OBJTAG::TAG_END; i++) {
		for (auto iter : pInstance->objectList[i])
		{
			if (iter != _pObj)
				continue;

			return true;
		}
	}
	return false;
}

bool PKH::CollisionManager4::FindObjectDelete(GameObject* _pObj)
{
	if (_pObj == nullptr)
		return false;

	for (int i = 0; i < OBJTAG::TAG_END; i++) {
		auto iter = pInstance->objectList[i].begin();
		auto end = pInstance->objectList[i].end();
		for (; iter != end; ++iter)
		{
			if (*iter != _pObj)
				continue;
			pInstance->objectList[i].erase(iter);
			return true;
		}
	}
	return false;
}

bool PKH::CollisionManager4::IsCollided(GameObject* target, GameObject* other)
{
	return false;
}

void PKH::CollisionManager4::MonsterToPBulletCollision()
{
	auto srciter = pInstance->objectList[MONSTER].begin();
	auto srcend = pInstance->objectList[MONSTER].end();
	bool CollisionCheck = false;
	for (; srciter != srcend;) // ¸÷
	{	
		auto dstiter = pInstance->objectList[PLAYER_BULLET].begin();
		auto dstend = pInstance->objectList[PLAYER_BULLET].end();
		for (; dstiter != dstend;) // ÃÑ¾Ë
		{
			//if (src == dest)
			//	continue;
			if (CheckSphere(*srciter, *dstiter))
			{
				//(*srciter)->OnCollision(*dstiter);
				//(*dstiter)->OnCollision(*srciter);
				//(*srciter)->isDead = true;
				(*dstiter)->isDead = true;
				//pInstance->objectList[MONSTER].erase(srciter);
				dstiter = pInstance->objectList[PLAYER_BULLET].erase(dstiter);
				//srciter = pInstance->objectList[MONSTER].erase(dstiter);
				CollisionCheck = true;
				break;
			}
			else {
				++dstiter;
			}
		}
		if (CollisionCheck) {
			CollisionCheck = false;
			(*srciter)->isDead = true;
			srciter = pInstance->objectList[MONSTER].erase(srciter);
		}
		else {
			++srciter;
		}
	}
}