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
        virtual void Render(Vector3 _pos, Vector3 _aixs);
        

        virtual IComponent* Clone() override;
    };

}