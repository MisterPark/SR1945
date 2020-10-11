#pragma once
#include "GameObject.h"

class Boss02 :
	public GameObject
{
public:
	explicit Boss02();
	explicit Boss02(Vector3 pos, Vector3 look, GameObject* tar);
	virtual ~Boss02();

	// GameObject��(��) ���� ��ӵ�
	void Ready();
	virtual void Update() override;
	void Phase01();
	void Phase02();
	void Phase03();
	void Pattern01Bullet();
	void Pattern02Bullet();
	void Pattern03Bullet();
	void Chase();
	virtual void OnCollision(GameObject* from);

private:
	bool canAttack = true;
	float coolTime = 0.f;
	float angle = 0.f;
	int hp = 60;
	int spawnType = 0;
	int spawnPattern = 1;
	GameObject* target;
};

