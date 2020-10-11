#pragma once
#include "GameObject.h"


namespace PKH
{
    class Monster03 :
        public GameObject
    {
    public:
        Monster03();
        
        virtual ~Monster03();
        // GameObject을(를) 통해 상속됨
        virtual void Update() override;
        float tick = 0.f;
        int BossSkill = 0;
        float delay = 2.f;
        
        float movePattern = 0.f;
        bool xType = false;
        bool yType = false;
        float yTypex = 0.f;

        float DieTime = 0.f;
        Vector3 Target = { 0.f,0.f,0.f };

        

        bool BossType = false;
        float BossRotateSpeed = 1.f;
        int MyColor = 0;

        bool isSetting = false;
        int Maxhp = 1;
        int hp = 1;
    };
}
