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
