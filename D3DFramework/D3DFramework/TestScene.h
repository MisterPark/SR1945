#pragma once
#include "IScene.h"
#include "Player.h"

using namespace PKH;


class TestScene :
    public IScene
{
    // IScene을(를) 통해 상속됨
    virtual void OnLoaded() override;
    virtual void OnUnloaded() override;
    virtual void Update() override;

    float time = 0.f;
    float bossTime = 60.f;
    bool bossFlag = false;

   Player* p = nullptr;

};
