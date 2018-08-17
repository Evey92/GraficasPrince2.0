#include "stdafx.h"
#include "InputLayout.h"


InputLayout::InputLayout()
{
}


InputLayout::~InputLayout()
{
}



void InputLayout::InitInputLayout()
{
	D3D11_INPUT_ELEMENT_DESC inputDesc;
	memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
	inputDesc.SemanticName = "POSITION";
	inputDesc.SemanticIndex = 0;
	inputDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	inputDesc.InputSlot = 0;
	inputDesc.AlignedByteOffset = 0;
	inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputDesc.InstanceDataStepRate = 0;
	m_descvector.push_back(inputDesc);
}
HRESULT InputLayout::CreateInputBuffer(ID3D11Device* m_pd3dDevice, Shader shader)
{
	HRESULT hr = S_OK;
	// Define the input layout
	D3D11_INPUT_ELEMENT_DESC inputDesc;
	memset(&inputDesc, 0, sizeof(D3D11_INPUT_ELEMENT_DESC));
	inputDesc.SemanticName = "POSITION";
	inputDesc.SemanticIndex = 0;
	inputDesc.Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	inputDesc.InputSlot = 0;
	inputDesc.AlignedByteOffset = 0;
	inputDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputDesc.InstanceDataStepRate = 0;
	m_descvector.push_back(inputDesc);

	// Create the input layout
	hr = m_pd3dDevice->CreateInputLayout(&m_descvector[0], (UINT)m_descvector.size(), shader.m_pVSBlob->GetBufferPointer(),
		shader.m_pVSBlob->GetBufferSize(), &m_layout);

	shader.m_pVSBlob->Release();
	if (FAILED(hr))
		return hr;

}

void InputLayout::SetInputLayout(ID3D11DeviceContext* pImmediateContext)
{
	pImmediateContext->IASetInputLayout(m_layout);
}
