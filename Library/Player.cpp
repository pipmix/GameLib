#include "Player.h"


Player::Player() {


	speed = 2.0f;

	position = Vector2(0.0f, -20.0f);
	velocity = Vector2(0.0f, 0.0f);
	collision = { 0,0,16,16 };

	collisionOffset = 2;
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
	UpdateCollision();

	DebugF2_01 = &point_L;
	DebugF2_02 = &point_T;
	DebugF2_03 = &point_R;
	DebugF2_04 = &point_B;


	DebugF4_01 = &collision;
	//collision = { collisionOffset, collisionOffset, 16 - collisionOffset , 16 };

	

}

void Player::Update(float t) {

	// INPUT
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






	velocity.y += 10.0f;

	if (jump) 
		if (isJumping == false) {
			//isJumping = true;
			velocity.y -= 1160.0f;

	}



	if (velocity.y == 0.0f) isJumping = false;
		
		
		


	if (up)velocity.y		= -1 * speed;
	if (down)velocity.y		= 1 * speed;
	if (left)velocity.x		= -1 * speed;
	if (right)velocity.x	= 1 *speed;

	position.x += velocity.x;
	position.y += velocity.y;

	velocity.x = velocity.x * 0.3f;
	velocity.y = velocity.y * 0.3f;




	up = down = left = right = jump = 0;
	

	UpdateCollision();




}
void Player::Draw() {


	sb->Draw(texture->textureResourceView, position, &texture->sourceRect);
	//		batch->Draw(mTexture.Get(), screenPos, &sourceRect, DirectX::Colors::White,mRotation, mOrigin, mScale, DirectX::SpriteEffects_None, mDepth);

}


void Player::UpdateEdgePoints() {

	long collisionMidpointX = (collision.z + collision.x)/2;
	long collisionMidpointY = (collision.w + collision.y)/2;

	point_L = { (float)(collision.x - edgePointOffset) , (float)collisionMidpointY };	//		x1
	point_T = { (float)collisionMidpointX , (float)(collision.y - edgePointOffset) };		//		y1
	point_R = { (float)(collision.z + edgePointOffset) , (float)collisionMidpointY };	//	x2
	point_B = { (float)collisionMidpointX , (float)(collision.w + edgePointOffset) };	//	y2

	edgeCollide_L = edgeCollide_T = edgeCollide_R = edgeCollide_B = 0;
}

void Player::UpdateCollision(){

	//collision = { (long)position.x + (long)collisionOffset, (long)position.y + (long)collisionOffset, ((long)position.x + 16) - (long)collisionOffset, ((long)position.y + 16) };
	collision = { position.x + collisionOffset, position.y - collisionOffset, (position.x + 16) - collisionOffset, (position.y + 16) };
	UpdateEdgePoints();
}


void Player::UpdateAnimation() {

	if (timeElapsed > animationFrameTime) {
		// increase frame
		timeElapsed -= animationFrameTime;



	}
	float timeElapsed;



	//currentFrame = ab->animations[anim].animStartFrame

}