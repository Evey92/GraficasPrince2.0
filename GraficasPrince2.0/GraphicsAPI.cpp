#include "stdafx.h"
#include "GraphicsAPI.h"



GraphicsAPI::GraphicsAPI()
{
}


GraphicsAPI::~GraphicsAPI()
{
}

HRESULT GraphicsAPI::InitializeGFXAPI(HWND g_hWnd)
{
	HRESULT hr = m_Device.InitDevice(g_hWnd);
	if (FAILED(hr))
	{
		return hr;
	}

	hr = m_texture.CreateRenderTargetView(m_Device.m_pd3dDevice, m_Device.m_SwapChain, m_Device.m_pRenderTargetView);
	if (FAILED(hr))
	{
		return hr;
	}
	
	m_viewPort.CreateViewPort(m_Device.width, m_Device.height, 1.0f, 1.0f);
	m_viewPort.SetViewPort(m_Device.m_pImmediateContext);

	m_shader.CompileVertexShader(m_Device.m_pd3dDevice, "Tutorial02.fx");

	m_inputLayout.CreateInputBuffer(m_Device.m_pd3dDevice, m_shader);
	m_inputLayout.SetInputLayout(m_Device.m_pImmediateContext);

	m_shader.CompilePixelShader(m_Device.m_pd3dDevice, "Tutorial02.fx");

	m_GraphicsBuffer.CreateVertexBuffer(m_Device.m_pd3dDevice);
	m_GraphicsBuffer.SetVertexBuffer(m_Device.m_pImmediateContext);

	m_Device.m_pImmediateContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

}

void GraphicsAPI::Render()
{
	
	float ClearColor[4] = { 0.0f, 0.125f, 0.3f, 1.0f }; // red,green,blue,alpha
	m_Device.m_pImmediateContext->ClearRenderTargetView(m_Device.m_pRenderTargetView, ClearColor);

	// Render a triangle
	m_Device.m_pImmediateContext->VSSetShader(m_shader.m_pVertexShader, NULL, 0);
	m_Device.m_pImmediateContext->PSSetShader(m_shader.m_pPixelShader, NULL, 0);
	m_Device.m_pImmediateContext->Draw(3, 0);

	// Present the information rendered to the back buffer to the front buffer (the screen)
	m_Device.m_SwapChain->Present(0, 0);

}
