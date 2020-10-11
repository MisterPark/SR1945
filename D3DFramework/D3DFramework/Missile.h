#pragma once
#include "GameObject.h"

namespace PKH
{
    class Missile :
        public GameObject
    {
    public:
        Missile();
        virtual ~Missile();

        virtual void Update() override;
        virtual void Die();
        virtual void OnCollision(GameObject* target);

    public:
        GameObject* target = nullptr;
        Vector3 targetPos;
        bool isAlliance = true;

        float lifeTick = 0.f;
        float lifeTime = 5.f;
    };

}

