#pragma once
#include <d3d11.h>
#include <string>
#include "Device.h"
#include "GraphicsBuffers.h"
#include <d3dcompiler.h>
#include <fstream>
#include <iostream>

class Shader
{
public:
	
	ID3DBlob * m_pVSBlob = NULL;
	ID3DBlob * m_pPSBlob = NULL;
	ID3D11VertexShader* m_pVertexShader = NULL;
	ID3D11PixelShader* m_pPixelShader = NULL;
	//WCHAR

	Shader()
	{
	}


	~Shader()
	{
	}
	HRESULT CompileVertexShader(ID3D11Device* m_pd3dDevice, const char* szFileName);
	HRESULT CompilePixelShader(ID3D11Device* m_pd3dDevice, const char* szFileName);

};

