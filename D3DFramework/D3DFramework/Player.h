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
		void RotateProcess();

		float attackTick = 0.f;
		float attackDelay = 0.2f;
		bool attackFlag = true;
		int hp = 100;
	};


}
