#pragma once
#include "../stdafx.h"

extern std::wstring gPath;

class Texture {
	public:

		Texture(std::wstring fileName, ID3D11Device* d);
		~Texture();

		void SetAsTileMap(int noX, int noY, int tW, int tH);


		int texTileSizeX = 0;
		int texTileSizeY = 0;

		int noColumns = 0;
		int noRows = 0;

		int curColumn = 0;
		int curRow = 0;


		std::wstring	_textureName;
		ID3D11ShaderResourceView* textureResourceView;

};