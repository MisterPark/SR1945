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


		float tick = 0.f;
		float delay = 2.f;
	};


}
