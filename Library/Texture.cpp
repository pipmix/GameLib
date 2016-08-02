#include "Texture.h"

Texture::Texture(std::wstring n, ID3D11Device* d) : _textureName(n) {

	std::wstring s = gPath + L"Textures/" + _textureName + L".dds";

	CreateDDSTextureFromFile(d, s.c_str(), NULL, &textureResourceView, NULL);

}


void Texture::SetAsTileMap(int noX, int noY, int tW, int tH) {

	noXTiles = noX;
	noYTiles = noY;

	texTileSizeX = tW;
	texTileSizeY = tH;

}