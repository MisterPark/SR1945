#pragma once
#include "GameObject.h"


namespace PKH
{
    class Bullet :
        public GameObject
    {
    public:
        Bullet();
       
        virtual ~Bullet();
        // GameObject��(��) ���� ��ӵ�
        virtual void Update() override;
        Vector3 TargetPos;
        bool MyBullet = false;
    };
}
