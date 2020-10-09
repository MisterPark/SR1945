#pragma once

#include "Enum02.h"

namespace PKH
{
	class GameObject;
	class Transform;
}

class MyCollisionManager
{
private:
	MyCollisionManager();
	~MyCollisionManager();

public:
	static MyCollisionManager* GetInstance();
	static void DestroyInstance();

public:
	void RegisterObject(OBJTAG tag, GameObject* obj);
	void Collide(OBJTAG dst, OBJTAG src);
	bool IsCollision(Transform* dst, Transform* src);

private:
	void Release();

private:
	static MyCollisionManager* instance;
	list<GameObject*> objList[OBJTAG::END];
};

