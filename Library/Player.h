#pragma once
#include "GameObj.h"




class Player : public GameObj{



public:
	Player();

	void Update(float t);
	void Draw();


	bool invulnerable = 0;
	bool isDead = 0;
	int health = 0;


};