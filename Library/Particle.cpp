#include "Particle.h"

Particle::Particle() :
	position(0.0f,0.0f), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f) {



}


Particle::Particle(XMFLOAT2 pos) : 
	position(pos), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f) {

	


}

Particle::Particle(XMFLOAT2 pos, XMFLOAT2 vel) :
	position(pos), velocity(0.0f, 0.0f), acceleration(0.0f, 0.0f) {





}

Particle::Particle(XMFLOAT2 pos, XMFLOAT2 vel, XMFLOAT2 acc) :
	position(pos), velocity(vel), acceleration(acc){


}


void Particle::Update() {

	position.x += velocity.x;
	position.y += velocity.y;

	velocity.x += acceleration.x;
	velocity.y += acceleration.y;



	//Util::Add(position,velocity);
	//Util::Add(velocity, acceleration);

}


void Particle::Draw() {


}




void Particle::SetSpeed(XMFLOAT2& vec, float spd) {
	float a = Angle(vec);
	vec.x = cos(a) * spd;
	vec.y = sin(a) * spd;
}

void Particle::SetAngle(XMFLOAT2& vec, float ang) {
	float s = Speed(vec);
	vec.x = cos(ang) * s;
	vec.y = sin(ang) * s;

}


float Particle::Angle(XMFLOAT2& vec) {
	return atan2(vec.y, vec.x);
}

float Particle::Speed(XMFLOAT2& vec) {
	return sqrt(vec.x*vec.x + vec.y * vec.y);
}