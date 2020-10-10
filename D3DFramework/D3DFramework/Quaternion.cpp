#include "stdafx.h"
#include "Quaternion.h"

PKH::Quaternion::Quaternion() :D3DXQUATERNION()
{
}

PKH::Quaternion::Quaternion(const FLOAT* r) :D3DXQUATERNION(r)
{
}

PKH::Quaternion::Quaternion(FLOAT fx, FLOAT fy, FLOAT fz, FLOAT fw) : D3DXQUATERNION(fx,fy,fz,fw)
{
}

PKH::Quaternion::Quaternion(const D3DXQUATERNION& r) :D3DXQUATERNION(r)
{
}

PKH::Quaternion::~Quaternion()
{
}

Vector3 PKH::Quaternion::ToEulerAngles(const Quaternion& _quat)
{
    Vector3 euler;
    float x, y, z, w;
    x = _quat.x;
    y = _quat.y;
    z = _quat.z;
    w = _quat.w;

    float sqx = x * x;
    float sqy = y * y;
    float sqz = z * z;
    float sqw = w * w;

    euler.x = (atan2f(2.f * (y * z + x * w), (-sqx - sqy + sqz + sqw)) * D3DX_PI);
    euler.y = (asinf(-2.f * (x * z - y * w)) * D3DX_PI);
    euler.z = (atan2f(2.f * (x * y + z * w), (sqx - sqy - sqz + sqw)) * D3DX_PI);

    return euler;
}
