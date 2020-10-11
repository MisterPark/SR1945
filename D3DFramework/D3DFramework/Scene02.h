#pragma once
#include "IScene.h"

using namespace PKH;

class Player02;

class Scene02 :
	public IScene
{
public:
	// IScene을(를) 통해 상속됨
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;

	void SpawnEnemy01(Vector3 pos, Vector3 look);
	void SpawnEnemy02(Vector3 pos, Vector3 look);
	void SpawnBoss(Vector3 pos, Vector3 look);

private:
	Player02* myPlayer;
};

