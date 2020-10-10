#pragma once

namespace PKH {
	class CollisionManager4
	{
	public:
		enum OBJTAG{PLAYER, PLAYER_BULLET, MONSTER, MONSTER_BULLET, BOSS, TAG_END};

	private:
		CollisionManager4();
		~CollisionManager4();

	public:
		static CollisionManager4* GetInstance();
		static void Destroy();

		static void CollisionSphere(GameObject* rDstObj, GameObject* rSrcObj);
		static bool CheckSphere(GameObject* rDstObj, GameObject* rSrcObj);

		static void Update();
		static void RegisterObject(OBJTAG _ObjTag, GameObject* _pObj);
		static void DisregisterObject(GameObject* _pObj);
		static bool FindObject(GameObject* _pObj);

		static bool FindObjectDelete(GameObject* _pObj);

		static bool IsCollided(GameObject* target, GameObject* other);

		static void MonsterToPBulletCollision();

		static PKH::CollisionManager4* pInstance;
		list<GameObject*> objectList[OBJTAG::TAG_END];

	};

}

