#include "Player.h"


Player::Player() {


	speed = 2.0f;

	position = Vector2(0.0f, -20.0f);
	velocity = Vector2(0.0f, 0.0f);
	collision = { 0,0,16,16 };

	collisionOffset = 0;
	edgePointOffset = 1;

	edgeCollide_L = 0;
	edgeCollide_T = 0;
	edgeCollide_R = 0;
	edgeCollide_B = 0;

	point_L = { 0,0 };
	point_T = { 0,0 };
	point_R = { 0,0 };
	point_B = { 0,0 };


	
}

void Player::InitCollision() {
	int _midX = texture->tileW / 2;
	int _midY = texture->tileH / 2;
	int _base = texture->tileH;
	midpoint = { (float)_midX , (float)_midY };
	basepoint = { (float)_midX , (float)_base };
	//collisionH;
	//collisionW;
	collisionOffset = 2;
	collision = { collisionOffset, collisionOffset, 16 - collisionOffset , 16 };

	SetEdgePoints();

}

void Player::Update(float t) {

	if (hWnd == GetFocus()){

		BYTE keyboardState[256];
		input->GetKeyboard()->Acquire();
		input->GetKeyboard()->GetDeviceState(sizeof(keyboardState), (LPVOID)&keyboardState);

		if (keyboardState[DIK_UP] || keyboardState[DIK_W]) up = 1;
		if (keyboardState[DIK_LEFT] || keyboardState[DIK_A]) left = 1;
		if (keyboardState[DIK_RIGHT] || keyboardState[DIK_D]) right = 1;
		if (keyboardState[DIK_DOWN] || keyboardState[DIK_S]) down = 1;
		if (keyboardState[DIK_SPACE]) jump = 1;

	}


	// EDGE COLLIDE TEST

	velocity.y += 8.0f;

	if (jump) 
		if (isJumping == false) {
			isJumping = true;
			velocity.y -= 160.0f;

		}

	if (velocity.y == 0.0f) isJumping = false;
		
		
		


	if (up)velocity.y		= -1 * speed;
	if (down)velocity.y		= 1 * speed;
	if (left)velocity.x		= -1 * speed;
	if (right)velocity.x	= 1 *speed;

	position += velocity;

	velocity.x = velocity.x * 0.3f;
	velocity.y = velocity.y * 0.3f;


	SetCollision();

	
	SetEdgePoints();
	up = down = left = right = jump = 0;


}
void Player::Draw() {


	sb->Draw(texture->textureResourceView, position, &texture->sourceRect);

}


void Player::SetEdgePoints() {

	long collisionMidpointX = collision.bottom - collision.top;
	long collisionMidpointY = collision.right - collision.left;

	point_L = { collision.left - edgePointOffset , collisionMidpointY };
	point_T = { collisionMidpointX , collision.top - edgePointOffset };
	point_R = { collision.right + edgePointOffset , collisionMidpointY };
	point_B = { collisionMidpointX , collision.bottom + edgePointOffset };

}

void Player::SetCollision(){
	collision = { (long)position.x + (long)collisionOffset, (long)position.y + (long)collisionOffset, ((long)position.x + 16) - (long)collisionOffset, ((long)position.y + 16) };
}
