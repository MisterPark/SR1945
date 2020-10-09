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
		bool Get_Dimension2D() { return Dimension2D; }
		bool Get_DimensionChangeCheck() { return DimensionChangeCheck; }
	private:
		void CreateBullet(int Code);
		bool Key_C;
		bool Key_V;
		bool Key_T;
		bool Dimension2D;
		bool DimensionChangeCheck;
	};


}
