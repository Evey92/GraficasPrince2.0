#include "stdafx.h"
#include "GraphicsBuffers.h"


HRESULT GraphicsBuffers::CreateVertexBuffer(ID3D11Device* m_pd3dDevice)
{
	HRESULT hr = S_OK;
	Vertex vertices[] =
	{
		Vector3(0.0f, 0.5f, 0.5f),
		Vector3(0.5f, -0.5f, 0.5f),
		Vector3(-0.5f, -0.5f, 0.5f),
	};

	D3D11_BUFFER_DESC bd;
	ZeroMemory(&bd, sizeof(bd));
	bd.Usage = D3D11_USAGE_DEFAULT;
	bd.ByteWidth = sizeof(Vertex) * 3;
	bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bd.CPUAccessFlags = 0;
	D3D11_SUBRESOURCE_DATA InitData;
	ZeroMemory(&InitData, sizeof(InitData));
	InitData.pSysMem = vertices;
	hr = m_pd3dDevice->CreateBuffer(&bd, &InitData, &m_pVertexBuffer);
	if (FAILED(hr))
		return hr;
}

void GraphicsBuffers::SetVertexBuffer(ID3D11DeviceContext* pImmediateContext)
{
	UINT stride = sizeof(Vertex);
	UINT offset = 0;
	pImmediateContext->IASetVertexBuffers(0, 1, &m_pVertexBuffer, &stride, &offset);
}