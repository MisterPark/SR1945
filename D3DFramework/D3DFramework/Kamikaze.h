#pragma once

#include "Missile.h"

namespace PKH
{
	class Kamikaze :public Missile
	{
	public:
		Kamikaze();
		virtual ~Kamikaze();

		virtual void Update() override;
		virtual void Die();
		virtual void OnCollision(GameObject* target);


	};
}