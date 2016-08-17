#pragma once
#include "../stdafx.h"

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