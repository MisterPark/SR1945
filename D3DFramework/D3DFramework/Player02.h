#pragma once
#include "GameObject.h"

using namespace PKH;

class Player02 :
	public GameObject
{
public:
	Player02();
	virtual ~Player02();

	// GameObject을(를) 통해 상속됨
	virtual void Update() override;
	void Attack();

private:
	bool canAttack = true;
	float coolTime = 0.f;
};

