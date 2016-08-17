#pragma once
#include "GameObj.h"
#include "Input.h"


extern SpriteBatch* sb;
extern Input* input;

class Player{



public:
	Player();

	void Update(float t);
	void Draw();
	void SetEdgePoints();
	void SetCollision();

	void InitCollision();

	bool invulnerable = 0;
	bool isDead = 0;
	int health = 0;

	bool onGround = 0;

	float speed;

	bool up = 0;
	bool down = 0;
	bool left = 0;
	bool right = 0;
	bool jump = 0;


	Vector2 position;
	Vector2 velocity;

	RECT collision;
	XMVECTOR dir;

	Texture* texture;

	bool isJumping = 0;

	XMFLOAT2 midpoint;
	XMFLOAT2 basepoint;
	int collisionH;
	int collisionW;
	int collisionOffset;
	int edgePointOffset;


	bool edgeCollide_L;
	bool edgeCollide_T;
	bool edgeCollide_R;
	bool edgeCollide_B;

	POINT point_L;
	POINT point_T;
	POINT point_R;
	POINT point_B;
};