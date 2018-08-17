#pragma once
#include "Device.h"
#include <d3d11.h>

class ViewPort
{
public:
	D3D11_VIEWPORT m_viewPort;
	void CreateViewPort(float width, float height, float topLeftX, float topLeftY);
	void SetViewPort(ID3D11DeviceContext* pImmediateContext);
	ViewPort();
	~ViewPort();
};

