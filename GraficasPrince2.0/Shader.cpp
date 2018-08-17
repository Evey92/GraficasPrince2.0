#include "stdafx.h"
#include "Shader.h"



HRESULT CompileShaderFromFile(const char* szFileName, LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut)
{
	HRESULT hr = S_OK;

	DWORD dwShaderFlags = D3DCOMPILE_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
	// Set the D3DCOMPILE_DEBUG flag to embed debug information in the shaders.
	// Setting this flag improves the shader debugging experience, but still allows 
	// the shaders to be optimized and to run exactly the way they will run in 
	// the release configuration of this program.
	dwShaderFlags |= D3DCOMPILE_DEBUG;
#endif

	ID3DBlob* pErrorBlob;
	hr = D3DX11CompileFromFile((LPCWSTR)szFileName, NULL, NULL, szEntryPoint, szShaderModel,
		dwShaderFlags, 0, NULL, ppBlobOut, &pErrorBlob, NULL);
	if (FAILED(hr))
	{
		if (pErrorBlob != NULL)
			OutputDebugStringA((char*)pErrorBlob->GetBufferPointer());
		if (pErrorBlob) pErrorBlob->Release();
		return hr;
	}
	if (pErrorBlob) pErrorBlob->Release();

	return S_OK;
}



HRESULT Shader::CompileVertexShader(ID3D11Device* m_pd3dDevice, const char* szFileName)
{
	HRESULT hr = S_OK;
	hr = CompileShaderFromFile(szFileName, "VS", "vs_4_0", &m_pVSBlob);
	if (FAILED(hr))
	{
		MessageBox(NULL,
			L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
		return hr;
	}

	hr = m_pd3dDevice->CreateVertexShader(m_pVSBlob->GetBufferPointer(), m_pVSBlob->GetBufferSize(), NULL, &m_pVertexShader);
	if (FAILED(hr))
	{
		m_pVSBlob->Release();
		return hr;
	}
}

HRESULT Shader::CompilePixelShader(ID3D11Device* m_pd3dDevice, const char* szFileName)
{
	HRESULT hr = S_OK;
	hr = CompileShaderFromFile(szFileName, "PS", "ps_4_0", &m_pPSBlob);
	if (FAILED(hr))
	{
		MessageBox(NULL,
			L"The FX file cannot be compiled.  Please run this executable from the directory that contains the FX file.", L"Error", MB_OK);
		return hr;
	}

	hr = m_pd3dDevice->CreatePixelShader(m_pPSBlob->GetBufferPointer(), m_pPSBlob->GetBufferSize(), NULL, &m_pPixelShader);
	m_pPSBlob->Release();
	if (FAILED(hr))
		return hr;
}
