#pragma once
#include "GameObject.h"


namespace PKH
{
    class Dust03 :
        public GameObject
    {
    public:
        Dust03();

        virtual ~Dust03();
        // GameObject��(��) ���� ��ӵ�
        virtual void Update() override;

        float tick = 0.f;
        float DieTime = 0.f;
        float delay = 1.f;

        bool isSetting = false;
    };
}
