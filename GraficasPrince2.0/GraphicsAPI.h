#pragma once
#include <d3d11.h>
#include "Device.h"
#include "ViewPort.h"
#include "Texture.h"
#include "Math.h"
#include "InputLayout.h"
#include "GraphicsBuffers.h"
#include "Shader.h"

class GraphicsAPI
{
public:
	Device m_Device;
	ViewPort m_viewPort;
	Texture m_texture;
	HRESULT InitializeGFXAPI(HWND g_hWnd);
	Vertex m_vertex;
	InputLayout m_inputLayout;
	Shader m_shader;
	GraphicsBuffers m_GraphicsBuffer;
	void Render();
	GraphicsAPI();
	~GraphicsAPI();
};

