#pragma once
#include "GameObject.h"

namespace PKH
{
	class ExplosionEffect :
		public GameObject
	{
	public:
		ExplosionEffect();
		virtual ~ExplosionEffect();


		virtual void Update() override;

	};


}
