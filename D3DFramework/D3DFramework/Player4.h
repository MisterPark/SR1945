#pragma once
#include "GameObject.h"


namespace PKH
{
	class Player4 :
		public GameObject
	{
	public:
		Player4();
		virtual ~Player4();

		virtual void Update() override;
		bool Get_Dimension2D() { return Dimension3D; }
	private:
		void CreateBullet(int Code);
		bool Key_Z;
		bool Key_X;
		bool Key_T;
		bool Dimension3D;
	};


}
