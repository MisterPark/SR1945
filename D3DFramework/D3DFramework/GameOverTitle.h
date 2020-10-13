#pragma once
#include "GameObject.h"

namespace PKH
{
	class GameOverTitle :
		public GameObject
	{
	public:
		GameOverTitle();
		~GameOverTitle();



		// GameObject을(를) 통해 상속됨
		virtual void Update() override;
		virtual void Render() override;

	};


}
