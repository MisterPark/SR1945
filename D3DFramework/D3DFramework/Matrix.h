#pragma once
#include <d3dx9math.h>

namespace PKH
{
	class Matrix : public D3DXMATRIX
	{
	public:
		Matrix();
		Matrix(const D3DXMATRIX& r);
		~Matrix();

		using D3DXMATRIX::operator const FLOAT*;
		using D3DXMATRIX::operator FLOAT*;
		using D3DXMATRIX::operator*;
		using D3DXMATRIX::operator();
		using D3DXMATRIX::operator*=;
		using D3DXMATRIX::operator+;
		using D3DXMATRIX::operator+=;
		using D3DXMATRIX::operator-;
		using D3DXMATRIX::operator-=;
		using D3DXMATRIX::operator/;
		using D3DXMATRIX::operator/=;
		using D3DXMATRIX::operator==;
		using D3DXMATRIX::operator!=;
	
		static const Matrix identity;
	
	};
}


