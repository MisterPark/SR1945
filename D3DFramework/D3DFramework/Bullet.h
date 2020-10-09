#pragma once
#include "GameObject.h"


namespace PKH
{
    class Bullet :
        public GameObject
    {
    public:
        Bullet();
       
        virtual ~Bullet();
        // GameObject을(를) 통해 상속됨
        virtual void Update() override;
        Vector3 TargetPos;
        bool MyBullet = false;
    };
}
