#pragma once
#include "GameObject.h"


namespace PKH
{
    class Bullet03 :
        public GameObject
    {
    public:
        Bullet03();
       
        virtual ~Bullet03();
        // GameObject��(��) ���� ��ӵ�
        virtual void Update() override;
        Vector3 TargetPos;
        bool MyBullet03 = false;
    };
}
