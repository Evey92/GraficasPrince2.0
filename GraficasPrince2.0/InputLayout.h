#pragma once
#include <d3d11.h>
#include <d3dcompiler.h>
#include <vector>
#include <d3dcompiler.h>
#include <d3dx11.h>
#include "GraficasPrince2.0.h"
#include "Shader.h"

using std::vector;

class InputLayout
{
public:

	vector<D3D11_INPUT_ELEMENT_DESC> m_descvector;
	ID3D11InputLayout * m_layout;

	InputLayout();
	~InputLayout();
	void InitInputLayout();
	void SetInputLayout(ID3D11DeviceContext* pImmediateContext);

	HRESULT CreateInputBuffer(ID3D11Device* m_pd3dDevice, Shader shader);
};

