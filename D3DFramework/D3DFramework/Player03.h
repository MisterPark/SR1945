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

		virtual void PostRender()override;
		float tick = 0.f;
		float delay = 1.f;
		int hp = 1;
		int MyColor = 250;
		int SceneChange = 0;
	};


}
