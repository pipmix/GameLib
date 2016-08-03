#pragma once
#include "../stdafx.h"
#include "Texture.h"
#include "EngineDataTypes.h"



class GameObj {


public:

	//GameObj();
	virtual void Update(float t) = 0;
	virtual void Draw() = 0;


	XMFLOAT2 pos;
	XMFLOAT3 rot;
	XMFLOAT3 scale;
	XMFLOAT2 vel;


	XMFLOAT2 dirVector;
	XMFLOAT2 prevDirVector;

	XMFLOAT2 acc;
	XMFLOAT2 mid;
	XMFLOAT2 drag;
	RECT collision;

	bool isActive;

	Texture* tex;


	bool hasPhysics = 0;

	std::map<std::string, Animation*> animation;
	

	 


};
