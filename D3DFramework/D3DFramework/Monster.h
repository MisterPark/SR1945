#pragma once
#include "GameObject.h"


namespace PKH
{
    enum class MonsterPatternType
    {
        PATTERN_01,
        PATTERN_02,
        PATTERN_03,
    };
    class Monster :
        public GameObject
    {
    public:
        Monster();
        virtual ~Monster();
        // GameObject을(를) 통해 상속됨
        virtual void Update() override;
        virtual void OnCollision(GameObject* target);
        virtual void Die();
        virtual void PostRender() override;

        void SetAirWay();

        void Pattern1();
        void Pattern2();
        void Pattern3();

        void MoveToPlayer();

        void Attack();

    public:
        int hp = 3;
        float attackTick = 0.f;
        float attackDelay = 1.0f;
        MonsterPatternType type = MonsterPatternType::PATTERN_01;

        Vector3 dest1 = { 100,0,100 };
        Vector3 dest2 = { -100,100,0 };
        Vector3 dest3 = { 100,0,-100 };
    };
}
