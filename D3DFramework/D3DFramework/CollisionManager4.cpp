#include "stdafx.h"
#include "CollisionManager4.h"
#include "Player4.h"
#include "PlayerBullet4.h"
#include "Monster4.h"
#include "MonsterBullet4.h"
#include "Camera.h"

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
	//Release();
}

list<GameObject*>* PKH::CollisionManager4::GetObjList(OBJTAG _ObjTag)
{
	return &pInstance->objectList[_ObjTag];
}

list<GameObject*>* PKH::CollisionManager4::GetObjList2(int ObjTagNumber)
{
	return &pInstance->objectList[ObjTagNumber];
}

void PKH::CollisionManager4::CollisionSphere(GameObject* rDstObj, GameObject* rSrcObj)
{
	if (CheckSphere(rDstObj, rSrcObj)) {
		rDstObj->OnCollision(rSrcObj);
		rSrcObj->OnCollision(rDstObj);
	}
}

bool PKH::CollisionManager4::CheckSphereDemension(GameObject* rDstObj, GameObject* rSrcObj)
{
	// 3D 상태일때 && Monster 의 z 값이 플레이어와 다르면 -> 충돌이 아님
	// 2D 상태에서는 z축과 상관없이 모두다 충돌
	if (Camera::GetInstance()->GetProjection3D() && dynamic_cast<Monster4*>(rDstObj)->GetPosZ() != 0)
		return false;

	float fRadiusSum = (rDstObj->transform->scale.x * 0.15f) + (rSrcObj->transform->scale.x * 0.15f);
	float fX = rDstObj->transform->position.x - rSrcObj->transform->position.x;
	float fY = rDstObj->transform->position.y - rSrcObj->transform->position.y;
	float fDist = sqrtf(fX * fX + fY * fY);
	return fDist <= fRadiusSum;

	return false;
}

bool PKH::CollisionManager4::CheckSphere(GameObject* rDstObj, GameObject* rSrcObj)
{
	//float fRadiusSum = (rDstObj->transform->scale.x * 0.25f) + (rSrcObj->transform->scale.x * 0.25f);
	//float fX = rDstObj->transform->position.x - rSrcObj->transform->position.x;
	//float fY = rDstObj->transform->position.y - rSrcObj->transform->position.y;
	//float fZ = rDstObj->transform->position.z - rSrcObj->transform->position.z;
	//float fDist = sqrtf(fX * fX + fY * fY + fZ * fZ);
	//return fDist < fRadiusSum;

	Vector3 target = rDstObj->transform->position - rSrcObj->transform->position;

	float dstRadius = rDstObj->transform->scale.z * 0.1f;
	float srcRadius = rSrcObj->transform->scale.z * 0.1f;

	float distance = D3DXVec3LengthSq(&target);

	if (distance <= dstRadius + srcRadius)
		return true;

	return false;
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
	if (nullptr == _pObj)//indObject(_pObj))
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
		for (; iter != pInstance->objectList[i].end(); ++iter)
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
	for (; srciter != pInstance->objectList[MONSTER].end();) // 몹
	{	
		bool CollisionCheck = false;
		auto dstiter = pInstance->objectList[PLAYER_BULLET].begin();
		
		for (; dstiter != pInstance->objectList[PLAYER_BULLET].end();) // 총알
		{
			//if (src == dest)
			//	continue;
			if (CheckSphereDemension(*srciter, *dstiter))
			{
				(*srciter)->OnCollision(*dstiter);
				(*dstiter)->OnCollision(*srciter);
				
				srciter = pInstance->objectList[MONSTER].erase(srciter);
				dstiter = pInstance->objectList[PLAYER_BULLET].erase(dstiter);
				//srciter = pInstance->objectList[MONSTER].erase(dstiter);
				CollisionCheck = true;
				break;
			}
			else {
				++dstiter;
			}
		}
		if (!CollisionCheck) {
			++srciter;
		}
	}
}

void PKH::CollisionManager4::Release()
{
	for (int i = 0; i < OBJTAG::TAG_END; ++i)
	{
		for (auto& iter : pInstance->objectList[i])
		{
			if (nullptr != iter)
			{
				delete iter;
				iter = nullptr;
			}
		}
		pInstance->objectList[i].clear();
	}
	pInstance->objectList->clear();
}