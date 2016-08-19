#pragma once


#include <windows.h>

#include <d3d11_1.h>
#include <DirectXMath.h>
#include "DDSTextureLoader.h"
#include "SimpleMath.h"
#include "Particle.h"
#pragma comment (lib, "d3d11.lib")


using namespace DirectX;


extern std::wstring gPath;

class Texture {
	public:

		Texture(std::wstring fileName, ID3D11Device* d);
		~Texture();

		void SetAsTileMap(int noX, int noY, int tW, int tH);


		void MoveSourceRect(int p);
		void MoveSourceRect(int x, int y);
		ID3D11ShaderResourceView* ReturnTRV();
		RECT* ReturnSourceRect();

		int tileW = 0;
		int tileH = 0;

		int noColumns = 0;
		int noRows = 0;

		int curColumn = 0;
		int curRow = 0;

		RECT sourceRect = { 0,0,0,0 };


		std::wstring	_textureName;
		ID3D11ShaderResourceView* textureResourceView;

};