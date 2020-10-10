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
	right = Vector3::RIGHT;
	up = Vector3::UP;
	look = Vector3::FORWARD;

	//fmodf(rotation.x, D3DXToRadian(180.f));
	//fmodf(rotation.y, D3DXToRadian(180.f));
	//fmodf(rotation.z, D3DXToRadian(180.f));

	Matrix rotX, rotY, rotZ;
	D3DXMatrixRotationX(&rotX, rotation.x);
	D3DXMatrixRotationY(&rotY, rotation.y);
	D3DXMatrixRotationZ(&rotZ, rotation.z);

	D3DXVec3TransformNormal(&right, &right, &rotX);
	D3DXVec3TransformNormal(&right, &right, &rotY);
	D3DXVec3TransformNormal(&right, &right, &rotZ);
	D3DXVec3TransformNormal(&up, &up, &rotX);
	D3DXVec3TransformNormal(&up, &up, &rotY);
	D3DXVec3TransformNormal(&up, &up, &rotZ);
	D3DXVec3TransformNormal(&look, &look, &rotX);
	D3DXVec3TransformNormal(&look, &look, &rotY);
	D3DXVec3TransformNormal(&look, &look, &rotZ);
	

}

IComponent* PKH::Transform::Clone()
{
    return new Transform(*this);
}

void PKH::Transform::Rotate(Vector3 _axis, float _angle)
{


	Matrix matRot;
	D3DXMatrixRotationAxis(&matRot, &_axis, _angle);


	//if(_axis != right)
	//	D3DXVec3TransformNormal(&right, &right, &matRot);
	//if (_axis != up)
	//	D3DXVec3TransformNormal(&up, &up, &matRot);
	//if (_axis != look)
	//	D3DXVec3TransformNormal(&look, &look, &matRot);

	rotation.x = atan2(matRot._23, matRot._33);
	rotation.y += atan2(-matRot._13, sqrt(pow(matRot._23, 2) + pow(matRot._33, 2)));
	//rotation.y = asinf(matRot._13);
	rotation.z = atan2(matRot._12, matRot._11);
	

}

void PKH::Transform::LookAt(Transform _target, Vector3 _worldUp)
{
	Vector3 dir = _target.position - position;

	//Vector3 axis = Vector3::Cross(&up, &dir);

	//float angle = acosf(Vector3::Dot(&up.Normalized(), &dir.Normalized()));

	//Rotate(axis, angle);
	//=================================
	// 테스트
	// Y축 회전
	//Vector3 v1 = Vector3::FORWARD - dir;
	//float rotY = atan2f(v1.x, v1.z) * 2.f;
	//rotation.y = rotY;// *TimeManager::DeltaTime();

	//// X축 회전
	//Vector3 v2 = Vector3::FORWARD - dir;
	//float rotX = ((atan2f(v2.z, v2.y)) * 2.f);
	//rotation.x = rotX;
	//================================


}

void PKH::Transform::LookAt(Vector3 _target, Vector3 _worldUp)
{
	Vector3 dir = _target - position;

	Vector3 axis = Vector3::Cross(&look, &dir);

	float angle = acosf(Vector3::Dot(&look.Normalized(), &dir.Normalized()));

	Rotate(axis, angle);
}
