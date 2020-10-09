#pragma once
#include "GameObject.h"


namespace PKH
{
    class Monster03_Boss :
        public GameObject
    {
    public:
        Monster03_Boss();
    
        virtual ~Monster03_Boss();
        // GameObject을(를) 통해 상속됨
        virtual void Update() override;
    };
}
