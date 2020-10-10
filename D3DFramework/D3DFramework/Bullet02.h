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

	// GameObject��(��) ���� ��ӵ�
	void Ready();
	virtual void Update() override;
	bool Culling();
	virtual void OnCollision(GameObject* from);

private:
	Vector3 dir;
	bool isPlayerType;
};

