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



		// GameObject��(��) ���� ��ӵ�
		virtual void Update() override;
		virtual void Render() override;

	};


}
