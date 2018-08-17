#pragma once
#include <d3d11.h>
#include <vector>



using std::vector;

class Device
{
public:
	ID3D11Device * m_pd3dDevice = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;
	IDXGISwapChain* m_SwapChain = nullptr;
	ID3D11RenderTargetView* m_pRenderTargetView = nullptr;
	ID3D11Texture2D* m_pDepthStencil = nullptr;
	ID3D11DepthStencilView* m_pDepthStencilView = nullptr;
	int width;
	int height;
	HRESULT InitDevice(HWND g_hWnd);
	void CleanupDevice();
	Device();
	~Device();



};

