#include "stdafx.h"
#include "transform.h"

using namespace PKH;

PKH::Transform::Transform()
{
}

PKH::Transform::~Transform()
{
}

void PKH::Transform::Update()
{
	rotation.x = fmodf(rotation.x, D3DXToRadian(360.f));
	rotation.y = fmodf(rotation.y, D3DXToRadian(360.f));
	rotation.z = fmodf(rotation.z, D3DXToRadian(360.f));
	
	LPDIRECT3DDEVICE9 device = D2DRenderManager::GetDevice();

	

	Matrix matTrans, rotX, rotY, rotZ, matScale;
	D3DXMatrixScaling(&matScale, scale.x, scale.y, scale.z);
	D3DXMatrixRotationX(&rotX, rotation.x);
	D3DXMatrixRotationY(&rotY, rotation.y);
	D3DXMatrixRotationZ(&rotZ, rotation.z);
	D3DXMatrixTranslation(&matTrans, position.x, position.y, position.z);

	world = matScale * rotX * rotY * rotZ * matTrans;

}

IComponent* PKH::Transform::Clone()
{
    return new Transform(*this);
}

void PKH::Transform::Rotate(Vector3 _axis, float _angle)
{
}

void PKH::Transform::LookAt(Transform _target, Vector3 _worldUp)
{
    Vector3 dir = _target.position - position;


}
