#pragma once
#include "GameObj.h"




class Player : public GameObj{



public:
	Player(string str);

	void Update(float t);
	void Draw();





};