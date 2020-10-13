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
	public:
		void DecHp(int Att) { PlayerHp -= Att; }
		int GetHp() { return PlayerHp; }
		bool Get_Dimension3D() { return Dimension3D; }
		float GetInvinTime() {return InvinTime; }
	private:
		void CreateBullet(int Code);
		void OnCollision(GameObject* target);
	private:
		bool Key_Z;
		bool Key_X;
		bool Key_T;
		bool Dimension3D;
		int PlayerHp;
		float SkillCoolTime;
		bool SkillCool;
		float InvinTime;
		float InvinEffect;
	};


}
