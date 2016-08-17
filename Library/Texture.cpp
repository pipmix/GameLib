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

	curRow = (p % noColumns) - 1; 
	curColumn = (p / noColumns); 

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

ID3D11ShaderResourceView* Texture::ReturnTRV() {
	return textureResourceView;
}

RECT* Texture::ReturnSourceRect() {
	return &sourceRect;
}