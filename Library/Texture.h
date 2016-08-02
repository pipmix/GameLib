#pragma once
#include "../stdafx.h"

extern std::wstring gPath;

class Texture {
	public:

		Texture(std::wstring fileName, ID3D11Device* d);
		~Texture();

		void SetAsTileMap(int noX, int noY);


		int texTileSizeX = 0;
		int texTileSizeX = 0;

		int noXTiles = 0;
		int noYTiles = 0;


		std::wstring	_textureName;
		ID3D11ShaderResourceView* textureResourceView;

};