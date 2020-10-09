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

        // Mesh을(를) 통해 상속됨

        virtual void Update() override;
        

        virtual IComponent* Clone() override;
    };

}