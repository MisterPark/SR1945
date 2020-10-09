#pragma once
#include "GameObject.h"

namespace PKH
{
    class MonsterBullet4 :
        public GameObject
    {
    public:
        // GameObject을(를) 통해 상속됨
        MonsterBullet4();
        ~MonsterBullet4();
        virtual void Update() override;
        void Ready();
    public:
        void SetCode(int CodeSet) { BulletCode = CodeSet; }

    public:
        GameObject* TargetPlayer;
        Vector3 TargetPos;
        int BulletCode;
        Vector3 dir;
    };
}

