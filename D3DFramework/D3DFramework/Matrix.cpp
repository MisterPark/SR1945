#include "stdafx.h"
#include "Matrix.h"

const PKH::Matrix identity = D3DXMATRIX(1, 0, 0, 0,
										0, 1, 0, 0,
										0, 0, 1, 0,
										0, 0, 0, 1);

PKH::Matrix::Matrix() : D3DXMATRIX()
{
}

PKH::Matrix::Matrix(const D3DXMATRIX& r) : D3DXMATRIX(r)
{
}

PKH::Matrix::~Matrix()
{
}
