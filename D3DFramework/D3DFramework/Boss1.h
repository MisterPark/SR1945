#pragma once
#include "GameObject.h"

namespace PKH
{
	enum class BossPatternType
	{
		PATTERN_00,
		PATTERN_01,
		PATTERN_02,
		PATTERN_03,
	};

	class Boss1 :
		public GameObject
	{
	public:
		Boss1();
		virtual ~Boss1();

		virtual void Update() override;
		virtual void OnCollision(GameObject* target);
		virtual void Die();
		virtual void PostRender() override;

		void Pattern0();
		void Pattern1();
		void Pattern2();
		void Pattern3();

		void PhaseUpdate();

	public:
		int hp = 300;
		float attackTick = 0.f;
		float attackDelay = 1.0f;
		bool attackFlag = true;

		float attack2Tick = 0.f;
		float attack2Delay = 1.0f;
		bool attack2Flag = true;

		float attack3Tick = 0.f;
		float attack3Delay = 5.0;
		bool attack3Flag = true;

		BossPatternType type = BossPatternType::PATTERN_00;
	};
}


