#pragma once
#include "IScene.h"

using namespace PKH;

class Scene02 :
	public IScene
{
public:
	// IScene��(��) ���� ��ӵ�
	virtual void OnLoaded() override;
	virtual void OnUnloaded() override;
	virtual void Update() override;
};

