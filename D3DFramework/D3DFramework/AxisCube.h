#pragma once
#include "Mesh.h"


namespace PKH
{
    class AxisCube :
        public Mesh
    {
    public:
        AxisCube();
        virtual ~AxisCube();

        // Mesh��(��) ���� ��ӵ�

        virtual void Update() override;
        

        virtual IComponent* Clone() override;
    };

}