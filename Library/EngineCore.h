#pragma once

#include <windows.h>
#include <tchar.h>
#include "SpriteBatch.h"
#include "CommonStates.h"
#include <string>
#include <Effects.h>
#include "Camera.h"
#include "EngineTimer.h"
#include "LevelData.h"
#include "Randomize.h"

extern int gWidth;
extern int gHeight;
extern int gScale;


extern SpriteBatch* sb;

 
extern HINSTANCE hInst;
extern HWND hWnd;
extern std::wstring gPath;

class EngineCore {

	public:
										EngineCore();
										~EngineCore();

										void Clear();



		ID3D11Device *					_device;
		ID3D11DeviceContext *			context;
		IDXGISwapChain *				_swapChain;
		ID3D11RenderTargetView*			rtv;
		ID3D11DepthStencilView*			dsv;
		ID3D11BlendState*				_blendState;
		CommonStates*					_commonStates;




		EngineTimer engineTimer;

		//Keyboard _keyboard;
		//Mouse _mouse;
		//GamePad _gamePad;
		//GamePad::ButtonStateTracker _buttons;




		// prim
		//PrimitiveBatch<VertexPositionColor> * _primitiveBatch;
		BasicEffect* _basicEffect;
		ID3D11InputLayout* _inputLayout;
		void const* shaderByteCode;
		size_t byteCodeLength;

		int w, h;

	
};