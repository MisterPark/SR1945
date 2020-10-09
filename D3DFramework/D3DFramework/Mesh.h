#pragma once
#include "IComponent.h"

namespace PKH
{
	class Mesh : public PKH::IComponent
	{
	public:
		Mesh();
		virtual ~Mesh();

		virtual void Update() {};
		virtual void Render();

		// IComponent��(��) ���� ��ӵ�
		virtual PKH::IComponent* Clone() override;

		void SetColor(D3DCOLOR color);

		IDirect3DVertexBuffer9* vb = nullptr;
		IDirect3DIndexBuffer9* triangles = nullptr;
		UINT vertexCount;
		UINT triangleCount;

		

		
	};
}


