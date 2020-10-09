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
        float delay = 2.f;
        
        float movePattern = 0.f;
        bool xType = false;
        bool BossType = false;

        bool isSetting = false;
    };
}
