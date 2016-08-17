#pragma once
#include "../stdafx.h"
#include "Texture.h"


class Sprite {


public:

	Sprite();


	XMFLOAT3 pos;
	XMFLOAT3 rot;
	XMFLOAT3 scale;
	RECT collision;

	Texture* text;






};