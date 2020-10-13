#pragma once
#include "GameObject.h"

namespace PKH
{
	class Player :
		public GameObject
	{
	public:
		Player();
		virtual ~Player();

		virtual void Update() override;
		virtual void OnCollision(GameObject* target);
		virtual void Die();
		virtual void PostRender() override;

		void Attack();
		void GuidedMissileAttack();
		void RotateProcess();

		void SetLockOnList();

		float attackTick = 0.f;
		float attackDelay = 0.2f;
		bool attackFlag = true;

		float attack2Tick = 0.f;
		float attack2Delay = 0.2f;
		bool attack2Flag = true;

		int hp = 100;

		bool isGameOver = false;

		list<GameObject*> lockOnList;
	};


}
