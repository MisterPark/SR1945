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

		void Attack();

		float attackTick = 0.f;
		float attackDelay = 0.2f;
		bool attackFlag = true;
	};


}
