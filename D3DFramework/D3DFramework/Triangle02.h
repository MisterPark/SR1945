#pragma once
#include "Mesh.h"

namespace PKH
{
    class Triangle02 :
        public Mesh
    {
    public:
		Triangle02();
		Triangle02(D3DCOLOR color);
        virtual ~Triangle02();

        // Mesh��(��) ���� ��ӵ�

        virtual void Update() override;

		virtual IComponent* Clone() override;
    };


}