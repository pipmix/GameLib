#pragma once


#include "SpriteBatch.h"
#include "../VS/GameLib/Util.h"



extern SpriteBatch* sb;


class Particle {


public:

	Particle();
	Particle(XMFLOAT2 pos);
	Particle(XMFLOAT2 pos, XMFLOAT2 vel);
	Particle(XMFLOAT2 pos, XMFLOAT2 vel, XMFLOAT2 acc);

	void Update();
	void Draw();





	XMFLOAT2 position;
	XMFLOAT2 velocity; //(spd, angle)
	XMFLOAT2 acceleration; //(spd, angle)
	XMFLOAT2 friction;


	void	Particle::SetSpeed(XMFLOAT2& vec, float spd);
	void	Particle::SetAngle(XMFLOAT2& vec, float ang);
	float	Particle::Angle(XMFLOAT2& vec);
	float	Particle::Speed(XMFLOAT2& vec);






};