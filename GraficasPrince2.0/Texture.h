#pragma once
#include <d3d11.h>

class Texture
{
public:
	ID3D11Texture2D * pBackBuffer = NULL;

	Texture();
	~Texture();
	HRESULT CreateRenderTargetView(ID3D11Device* pd3dDevice, IDXGISwapChain* pSwapChain, ID3D11RenderTargetView* m_pRenderTargetView);
};

