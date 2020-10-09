#pragma once
#include "GameObject.h"

using namespace PKH;

class Bullet02 :
	public GameObject
{
public:
	explicit Bullet02();
	explicit Bullet02(Vector3 pos, Vector3 scale, Vector3 look, bool isPlayer = true);
	virtual ~Bullet02();

	// GameObject을(를) 통해 상속됨
	void Ready();
	virtual void Update() override;

private:
	bool isPlayerType;
};

