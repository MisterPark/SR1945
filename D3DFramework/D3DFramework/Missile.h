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

    public:
        GameObject* target = nullptr;
        Vector3 targetPos;
    };

}

