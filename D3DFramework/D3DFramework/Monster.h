#pragma once
#include "GameObject.h"


namespace PKH
{
    class Monster :
        public GameObject
    {
    public:
        Monster();
        virtual ~Monster();
        // GameObject��(��) ���� ��ӵ�
        virtual void Update() override;
        virtual void OnCollision(GameObject* target);
        virtual void Die();

    public:
        int hp = 3;
    };
}
