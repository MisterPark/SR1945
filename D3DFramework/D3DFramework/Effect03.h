#pragma once
#include "GameObject.h"


namespace PKH
{
    class Effect03 :
        public GameObject
    {
    public:
        Effect03();

        virtual ~Effect03();
        // GameObject��(��) ���� ��ӵ�
        virtual void Update() override;
        
        float tick = 0.f;
        float delay = 1.f;

        int effectDir = 0;
        bool PlayerHit = false;

        bool isSetting = false;
    };
}
