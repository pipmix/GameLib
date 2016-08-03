#include "Player.h"


Player::Player() {

	walkSpeed = 100;
	runSpeed = 200;
	drag.x = walkSpeed * 4;

}

void Player::Update(float t) {

	prevDirVector = dirVector;
	acc.x = 0.0f;


	if (moves.attack)pos.x += 0.2;


	if (onGround) {


	}
	else {



	}

}
void Player::Draw() {


	sb->Draw(tex->textureResourceView, pos, &tex->sourceRect);

}