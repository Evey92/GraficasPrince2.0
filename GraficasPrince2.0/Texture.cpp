#include "stdafx.h"
#include "Texture.h"



Texture::Texture()
{
}


Texture::~Texture()
{
}

HRESULT Texture::CreateRenderTargetView(ID3D11Device* pd3dDevice, IDXGISwapChain* pSwapChain, ID3D11RenderTargetView* m_pRenderTargetView)
{
	HRESULT hr = S_OK;

	hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&pBackBuffer);
	if (FAILED(hr))
		return hr;

	hr = pd3dDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRenderTargetView);
	pBackBuffer->Release();
	if (FAILED(hr))
		return hr;

}

