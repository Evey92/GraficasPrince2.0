#include "stdafx.h"
#include "ViewPort.h"



ViewPort::ViewPort()
{
}


ViewPort::~ViewPort()
{
}

void ViewPort::CreateViewPort(float width, float height, float topLeftX, float topLeftY)
{
	m_viewPort.TopLeftX = topLeftX;
	m_viewPort.TopLeftY = topLeftY;
	m_viewPort.Width = width;
	m_viewPort.Height = height;
}
void ViewPort::SetViewPort(ID3D11DeviceContext* pImmediateContext)
{
	pImmediateContext->RSSetViewports(1, &m_viewPort);
}

