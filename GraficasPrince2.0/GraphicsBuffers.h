#pragma once
#include <d3d11.h>
#include <vector>
#include "InputLayout.h"
#include "Math.h"
#include "Shader.h"

class GraphicsBuffers
{
public:

	ID3D11Buffer * m_pBuffer = nullptr;
	ID3D11Buffer* m_pVertexBuffer = NULL;


	GraphicsBuffers() = default;
	virtual ~GraphicsBuffers()
	{
		if (m_pBuffer)
		{
			m_pBuffer->Release();
		}
	}

	HRESULT CreateVertexBuffer(ID3D11Device* m_pd3dDevice);
	void SetVertexBuffer(ID3D11DeviceContext* pImmediateContext);
	

	//VertexBuffer
	//IndexBuffer
};