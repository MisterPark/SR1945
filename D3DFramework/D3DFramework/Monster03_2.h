#pragma once
#include "GameObject.h"


namespace PKH
{
    class Monster03_2 :
        public GameObject
    {
    public:
        Monster03_2();
        virtual ~Monster03_2();
        // GameObject��(��) ���� ��ӵ�
        virtual void Update() override;
    };
}
