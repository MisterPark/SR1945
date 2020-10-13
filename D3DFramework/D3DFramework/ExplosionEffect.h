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

		float lifeTick = 0.f;
		float lifeTime = 1.f;

		int colorR = 255;
		int colorG = 0;
		int colorB = 0;
	};


}
