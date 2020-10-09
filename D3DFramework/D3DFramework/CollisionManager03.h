#pragma once

namespace PKH
{
	class CollisionManager03
	{
	private:
		CollisionManager03();
		~CollisionManager03();

	public:
		static CollisionManager03* GetInstance();
		static void Destroy();

		static void CollisionSphere(GameObject* rDstObj, GameObject* rSrcObj);
		static bool CheckSphere(GameObject* rDstObj, GameObject* rSrcObj);

		static void Update();
		static void RegisterObject(GameObject* _pObj);
		static void DisregisterObject(GameObject* _pObj);
		static bool FindObject(GameObject* _pObj);

		static bool IsCollided(GameObject* target, GameObject* other);

		vector<GameObject*> objectList;
	};


}

