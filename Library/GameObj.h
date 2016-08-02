#pragma once
#include "../stdafx.h"
#include "Texture.h"



class GameObj {


public:

	//GameObj();
	virtual void Update(float t) = 0;
	virtual void Draw() = 0;


	XMFLOAT2 pos;
	XMFLOAT3 rot;
	XMFLOAT3 scale;
	XMFLOAT2 vel;
	XMFLOAT2 mid;
	RECT collision;

	bool isActive;

	Texture* tex;


	 


};
