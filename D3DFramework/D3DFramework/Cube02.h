#pragma once
#include "Mesh.h"

namespace PKH
{
    class Cube02 :
        public Mesh
    {
    public:
		explicit Cube02();
		Cube02(D3DCOLOR color);
        virtual ~Cube02();

        // Mesh��(��) ���� ��ӵ�

        virtual void Update() override;

        virtual IComponent* Clone() override;
    };
}
