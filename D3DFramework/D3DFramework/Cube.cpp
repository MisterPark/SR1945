#include "stdafx.h"
#include "Cube.h"
#include "Player4.h"

PKH::Cube::Cube()
{
	this->vertexCount = 8;
	this->triangleCount = 12;
	

	D2DRenderManager::GetDevice()->CreateVertexBuffer(
		vertexCount * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,
		Vertex::FVF,
		D3DPOOL_MANAGED,
		&vb,
		0);

	D2DRenderManager::GetDevice()->CreateIndexBuffer(
		triangleCount * 3 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&triangles,
		0);

	Vertex* vertices;
	vb->Lock(0, 0, (void**)&vertices, 0);

	vertices[0] = Vertex(-0.1f, -0.1f, -0.1f, D3DCOLOR_XRGB(255, 0, 0));
	vertices[1] = Vertex(-0.1f, 0.1f, -0.1f, D3DCOLOR_XRGB(0, 255, 0));
	vertices[2] = Vertex(0.1f, 0.1f, -0.1f, D3DCOLOR_XRGB(0, 0, 255));
	vertices[3] = Vertex(0.1f, -0.1f, -0.1f, D3DCOLOR_XRGB(255, 0, 255));

	vertices[4] = Vertex(-0.1f, -0.1f, 0.1f, D3DCOLOR_XRGB(255, 0, 0));
	vertices[5] = Vertex(-0.1f, 0.1f, 0.1f, D3DCOLOR_XRGB(0, 255, 0));
	vertices[6] = Vertex(0.1f, 0.1f, 0.1f, D3DCOLOR_XRGB(0, 0, 255));
	vertices[7] = Vertex(0.1f, -0.1f, 0.1f, D3DCOLOR_XRGB(255, 0, 255));
	vb->Unlock();

	WORD* indices = nullptr;
	triangles->Lock(0, 0, (void**)&indices, 0);
	// 전
	indices[0] = 0; indices[1] = 1; indices[2] = 3;
	indices[3] = 1; indices[4] = 2; indices[5] = 3;
	// 후
	indices[6] = 7; indices[7] = 6; indices[8] = 4;
	indices[9] = 6; indices[10] = 5; indices[11] = 4;
	// 좌
	indices[12] = 4; indices[13] = 5; indices[14] = 0;
	indices[15] = 5; indices[16] = 1; indices[17] = 0;
	// 우
	indices[18] = 3; indices[19] = 2; indices[20] = 7;
	indices[21] = 2; indices[22] = 6; indices[23] = 7;
	// 상
	indices[24] = 1; indices[25] = 5; indices[26] = 2;
	indices[27] = 5; indices[28] = 6; indices[29] = 2;
	// 하
	indices[30] = 4; indices[31] = 0; indices[32] = 7;
	indices[33] = 0; indices[34] = 3; indices[35] = 7;
	triangles->Unlock();


}

PKH::Cube::~Cube()
{
}

void PKH::Cube::Update()
{

}


IComponent* PKH::Cube::Clone()
{
	return new Cube(*this);
}

void PKH::Cube::Scene4ToDimension() {
	GameObject* player = ObjectManager::GetInstance()->FindObject<Player4>();
	if (player == nullptr) {
		WORD* indices = nullptr;
		triangles->Lock(0, 0, (void**)&indices, 0);
		// 전
		indices[0] = 0; indices[1] = 1; indices[2] = 3;
		indices[3] = 1; indices[4] = 2; indices[5] = 3;
		// 후
		indices[6] = 7; indices[7] = 6; indices[8] = 4;
		indices[9] = 6; indices[10] = 5; indices[11] = 4;
		// 좌
		indices[12] = 4; indices[13] = 5; indices[14] = 0;
		indices[15] = 5; indices[16] = 1; indices[17] = 0;
		// 우
		indices[18] = 3; indices[19] = 2; indices[20] = 7;
		indices[21] = 2; indices[22] = 6; indices[23] = 7;
		// 상
		indices[24] = 1; indices[25] = 5; indices[26] = 2;
		indices[27] = 5; indices[28] = 6; indices[29] = 2;
		// 하
		indices[30] = 4; indices[31] = 0; indices[32] = 7;
		indices[33] = 0; indices[34] = 3; indices[35] = 7;
		triangles->Unlock();
		return;
	}
	if (dynamic_cast<Player4*>(player)->Get_Dimension2D()) {
		WORD* indices = nullptr;
		triangles->Lock(0, 0, (void**)&indices, 0);
		// 후
		indices[6] = 9; indices[7] = 9; indices[8] = 9;
		indices[9] = 9; indices[10] = 9; indices[11] = 9;
		// 좌
		indices[12] = 9; indices[13] = 9; indices[14] = 9;
		indices[15] = 9; indices[16] = 9; indices[17] = 9;
		// 우		 				   				    
		indices[18] = 9; indices[19] = 9; indices[20] = 9;
		indices[21] = 9; indices[22] = 9; indices[23] = 9;
		// 상		 				   				    
		indices[24] = 9; indices[25] = 9; indices[26] = 9;
		indices[27] = 9; indices[28] = 9; indices[29] = 9;
		// 하		 				   				    
		indices[30] = 9; indices[31] = 9; indices[32] = 9;
		indices[33] = 9; indices[34] = 9; indices[35] = 9;
		triangles->Unlock();
	}
	else {
		WORD* indices = nullptr;
		triangles->Lock(0, 0, (void**)&indices, 0);
		// 전
		indices[0] = 0; indices[1] = 1; indices[2] = 3;
		indices[3] = 1; indices[4] = 2; indices[5] = 3;
		// 후
		indices[6] = 7; indices[7] = 6; indices[8] = 4;
		indices[9] = 6; indices[10] = 5; indices[11] = 4;
		// 좌
		indices[12] = 4; indices[13] = 5; indices[14] = 0;
		indices[15] = 5; indices[16] = 1; indices[17] = 0;
		// 우
		indices[18] = 3; indices[19] = 2; indices[20] = 7;
		indices[21] = 2; indices[22] = 6; indices[23] = 7;
		// 상
		indices[24] = 1; indices[25] = 5; indices[26] = 2;
		indices[27] = 5; indices[28] = 6; indices[29] = 2;
		// 하
		indices[30] = 4; indices[31] = 0; indices[32] = 7;
		indices[33] = 0; indices[34] = 3; indices[35] = 7;
		triangles->Unlock();
	}
}