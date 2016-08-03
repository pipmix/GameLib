#pragma once
#include "GameObj.h"


extern SpriteBatch* sb;
extern Moves moves;

class Player : public GameObj{



public:
	Player();

	void Update(float t);
	void Draw();


	bool invulnerable = 0;
	bool isDead = 0;
	int health = 0;

	bool onGround = 0;

	float walkSpeed, runSpeed;


};