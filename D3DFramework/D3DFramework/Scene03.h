#pragma once
#include "IScene.h"
class Scene03 :
    public IScene
{
    // IScene��(��) ���� ��ӵ�
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;
    float tick = 0.f;

    float fdust = 0.f;
    int MonsterMakeCount = 0;
    int BossmakeCount = 0;
};

