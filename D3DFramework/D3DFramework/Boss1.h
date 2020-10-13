#pragma once
#include "GameObject.h"

namespace PKH
{
	enum class BossPatternType
	{
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

		void Pattern1();
		void Pattern2();
		void Pattern3();

		void Attack();

	public:
		int hp = 100;
		float attackTick = 0.f;
		float attackDelay = 1.0f;

		BossPatternType type = BossPatternType::PATTERN_01;
	};
}


