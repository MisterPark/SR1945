#include "stdafx.h"
#include "Bullet03.h"
#include "Player03.h"
#include "Monster03.h"

PKH::Bullet03::Bullet03()
{
	transform->scale = { 0.5f,0.5f,0.5f };
	moveSpeed = 10.f;
}



PKH::Bullet03::~Bullet03()
{
}

void PKH::Bullet03::Update()
{


	if (!MyBullet03)
	{
		GameObject* player = ObjectManager::GetInstance()->FindObject<Player03>();
		if (player != nullptr)
		{



			if (transform->position.z > 2.f)
			{
				Vector3 dir = player->transform->position - transform->position;
				Vector3::Normalize(&dir);
					Move(dir);

					float rotX = atan2f(dir.z, dir.y);
					float rotY = atan2f(dir.x, dir.z);
					float rotZ = atan2f(dir.y, dir.x);

					//if(transform->rotation.x < rotX)
					transform->rotation.x += rotX * TimeManager::DeltaTime();
					//if (transform->rotation.y < rotY)
					transform->rotation.y += rotY * TimeManager::DeltaTime();
					//if (transform->rotation.z < rotZ)
					transform->rotation.z += rotZ * TimeManager::DeltaTime();
					TargetPos = dir;
			}
			else
			{
			
				if (transform->position.x < 0.f)
					Move(TargetPos - Vector3{0,0,3.f});
				else
					Move(TargetPos - Vector3{ 0,0,3.f });
			}




		}
		if (transform->position.z < -2.f)
		{
			
			Die();
		}
	}
	if(MyBullet03)
	{


			GameObject* monster = ObjectManager::GetInstance()->FindObject<Monster03>();

			float fRadiusSum = static_cast<float>((transform->scale.x + 3.f) + (transform->scale.x) + 3.f);
			float fX = monster->transform->position.x - transform->position.x;
			float fY = monster->transform->position.y - transform->position.y;
			float fZ = monster->transform->position.z - transform->position.z;
			float fDist = sqrtf(fX * fX + fY * fY + fZ * fZ);
			if (fDist - fRadiusSum < 0)
			{
				if (monster != nullptr)
				{
					Vector3 mdir = monster->transform->position;
					Move(mdir);

					TargetPos = mdir;
				}
				else
				{
					Die();
				}
			}
			else
			{
				if (transform->position.z < 10)
					Move(Vector3{ 0.f,0.f,10.f });
				else
					Die();

			}

			
			fRadiusSum = static_cast<float>((transform->scale.x) + (transform->scale.x));
			fX = monster->transform->position.x - transform->position.x;
			fY = monster->transform->position.y - transform->position.y;
			fZ = monster->transform->position.z - transform->position.z;
			fDist = sqrtf(fX * fX + fY * fY + fZ * fZ);
			if (fDist - fRadiusSum < 0)
			{
				dynamic_cast<Monster03*>(monster)->hp--;
				Die();
			}

		//}
		//else
		//{
		//	GameObject* monster = ObjectManager::GetInstance()->FindObject<Monster03>();
		//	if (monster != nullptr)
		//	{
		//		Move(TargetPos);
		//	}
		//	else
		//	{
		//		Die();
		//	}
		//

		//}

	}
	for (auto& comp : components)
	{
		comp.second->Update();
	}
}

