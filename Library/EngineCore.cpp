#include "EngineCore.h"


EngineCore::EngineCore() {

	RECT clientRect;
	GetClientRect(hWnd, &clientRect);

	w= clientRect.right;
	h = clientRect.bottom;


	DXGI_SWAP_CHAIN_DESC swapChainDesc;
	ZeroMemory(&swapChainDesc, sizeof(swapChainDesc));
	swapChainDesc.BufferCount = 1;
	swapChainDesc.BufferDesc.Width = clientRect.right;
	swapChainDesc.BufferDesc.Height = clientRect.bottom;
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.BufferDesc.RefreshRate.Numerator = 60;
	swapChainDesc.BufferDesc.RefreshRate.Denominator = 1;
	swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.Windowed = true;
	swapChainDesc.SampleDesc.Count = 1;
	swapChainDesc.SampleDesc.Quality = 0;
	D3D11CreateDeviceAndSwapChain(0, D3D_DRIVER_TYPE_HARDWARE, 0, 0, 0, 0, D3D11_SDK_VERSION, &swapChainDesc, &_swapChain, &_device, 0, &context);
	ID3D11Texture2D* texture2d_backBuffer;
	_swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (LPVOID*)&texture2d_backBuffer);
	_device->CreateRenderTargetView(texture2d_backBuffer, 0,&rtv);
	texture2d_backBuffer->Release();
	context->OMSetRenderTargets(1, &rtv, 0);


	D3D11_VIEWPORT viewport;
	viewport.Width = static_cast<float>(clientRect.right);
	viewport.Height = static_cast<float>(clientRect.bottom);
	viewport.MinDepth = 0.0f;
	viewport.MaxDepth = 1.0f;
	viewport.TopLeftX = 0.0f;
	viewport.TopLeftY = 0.0f;
	context->RSSetViewports(1, &viewport);
	_commonStates = new CommonStates(_device);
	_blendState = _commonStates->AlphaBlend();
	context->OMGetBlendState(&_blendState, NULL, NULL);


	//m_timer = new TimerClass;
	sb = new SpriteBatch(context);



	_mouse.SetWindow(hWnd);

	//prim



}

EngineCore::~EngineCore() {



	rtv->Release();
	_swapChain->Release();
	context->Release();
	_device->Release();



}

void EngineCore::Clear() {

	/*
		// Clear the views
		context->ClearRenderTargetView(rtv, m_clearColor);
		context->ClearDepthStencilView(dsv.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

		context->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());

		CD3D11_VIEWPORT viewPort(0.0f, 0.0f, static_cast<float>(w), static_cast<float>(h));
		context->RSSetViewports(1, &viewPort);
	*/

}