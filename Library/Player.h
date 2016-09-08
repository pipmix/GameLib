#pragma once

#include <DirectXMath.h>
#include "SpriteBatch.h"
#include "Input.h"
#include "Texture.h"



extern SpriteBatch* sb;
extern Input* input;


extern RECT* DebugRect01;
extern RECT* DebugRect02;
extern RECT* DebugRect03;
extern RECT* DebugRect04;

extern XMFLOAT2* DebugF2_01;
extern XMFLOAT2* DebugF2_02;
extern XMFLOAT2* DebugF2_03;
extern XMFLOAT2* DebugF2_04;

extern XMFLOAT4* DebugF4_01;
extern XMFLOAT4* DebugF4_02;


class Player{



public:
	Player();

	void Update(float t);
	void Draw();
	void UpdateEdgePoints();
	void UpdateCollision();
	void UpdateAnimation();

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


	XMFLOAT2 position;
	XMFLOAT2 velocity;

	XMFLOAT4 collision;
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

	XMFLOAT2 point_L;
	XMFLOAT2 point_T;
	XMFLOAT2 point_R;
	XMFLOAT2 point_B;



	int currentFrame;
	int frameCount;

	float animationFrameTime;
	float timeElapsed;




};