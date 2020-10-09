#pragma once
#include "GameObject.h"

class Enemy02 :
	public GameObject
{
public:
	explicit Enemy02();
	explicit Enemy02(Vector3 pos, Vector3 look, int type = 0);
	virtual ~Enemy02();

	// GameObject을(를) 통해 상속됨
	void Ready();
	virtual void Update() override;
	void Attack();

private:
	bool canAttack = true;
	float coolTime = 0.f;
	int type = 0;
};

