#pragma once
#include "GameObject.h"

namespace PKH
{
	class Player03 :
		public GameObject
	{
	public:
		Player03();
		virtual ~Player03();

		virtual void Update() override;


		float tick = 0.f;
		float delay = 1.f;
		
	};


}
