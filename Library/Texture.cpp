#include "Texture.h"

Texture::Texture(std::wstring n, ID3D11Device* d) : _textureName(n) {

	std::wstring s = gPath + L"Textures/" + _textureName + L".dds";

	CreateDDSTextureFromFile(d, s.c_str(), NULL, &textureResourceView, NULL);

}


void Texture::SetAsTileMap(int noX, int noY, int tW, int tH) {

	noColumns = noX;
	noRows = noY;

	tileW = tW;
	tileH = tH;

	sourceRect = { 0, 0, tW, tH };

}

void Texture::MoveSourceRect(int p) {
	// moves to place
	// starts at 0
	curRow = (p % noColumns) - 1; // 2
	curColumn = (p / noColumns); //12

	sourceRect.left = (curRow * tileW);
	sourceRect.top = (curColumn * tileH);
	sourceRect.right = sourceRect.left + tileW;
	sourceRect.bottom = sourceRect.top + tileH;
}

void Texture::MoveSourceRect(int x, int y) {
	curRow = x;
	curColumn = y;

	sourceRect.left = (curRow * tileW);
	sourceRect.top = (curColumn * tileH);
	sourceRect.right = sourceRect.left + tileW;
	sourceRect.bottom = sourceRect.top + tileH;
}