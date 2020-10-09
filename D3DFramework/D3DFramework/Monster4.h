#pragma once
#include "GameObject.h"

namespace PKH
{
    class Monster4 :
        public GameObject
    {
    public:
        Monster4();
        virtual ~Monster4();
        // GameObject을(를) 통해 상속됨
        virtual void Update() override;
        void SetCode(int CodeSet) { MonsterCode = CodeSet; }
        void Ready();
    private:
        void MonsterPattern();

        void CreateBullet(int Code);

    public:
        GameObject* TargetPlayer;
        Vector3 TargetPos;
        int MonsterCode;
        Vector3 dir;
        float MonsterBulletRegenTime;
        float MonsterPatternTime;
    };
}
