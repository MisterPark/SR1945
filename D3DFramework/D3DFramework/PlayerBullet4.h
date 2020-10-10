#pragma once
#include "GameObject.h"

namespace PKH
{
    class PlayerBullet4 :
        public GameObject
    {
    public:
        // GameObject을(를) 통해 상속됨
        PlayerBullet4();
        ~PlayerBullet4();
        virtual void Update() override;
        void Ready();
    public:
        void SetCode(int CodeSet) { BulletCode = CodeSet; }

    public:
        GameObject* TargetMonster;
        Vector3 TargetPos;
        //Vector3 TargetPos;
        int BulletCode;
        float BulletPatternTime;
        int BulletPattern;
 
    };
}
