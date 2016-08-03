#include "Camera.h"
Camera::Camera() {

	FOV = XM_PI / 4.f;
	farPlane = 1000.f;
	nearPlane = 0.01f;



	XMStoreFloat4x4(&view, XMMatrixIdentity());
	speed = 5;
	zoom = 1.0f;
	updateMatrix = false;

	scale = { 1, 1, 1 };

	RECT clientRect;
	GetClientRect(hWnd, &clientRect);



	viewportWidth = clientRect.right;
	viewportHeight = clientRect.bottom;



	screenCenter = { (float)(viewportWidth / 2), (float)(viewportHeight / 2) };
	moveTo = { 0, 0, 0 };
}

XMMATRIX Camera::transformMatrix() {
	XMFLOAT2 cPos = { 250,250 };
	updateMatrix = true;

	if (updateMatrix) {

		float catchUpX;
		float catchUpY;
		float distanceX = roundf(abs(moveTo.x - cPos.x));
		float distanceY = roundf(abs(moveTo.y - cPos.y));

		if (distanceX >= 32)	catchUpX = 6.0f;
		else if (distanceX >= 16)	catchUpX = 6.0f;
		else if (distanceX >= 8)	catchUpX = 3.0f;
		else if (distanceX >= 4)	catchUpX = 1.7f;
		else if (distanceX >= 2)	catchUpX = 0.8f;
		else						catchUpX = 0.0f;

		if (distanceY >= 32)		catchUpY = 6.0f;
		else if (distanceY >= 16)	catchUpY = 6.0f;
		else if (distanceY >= 8)	catchUpY = 3.0f;
		else if (distanceY >= 4)	catchUpY = 1.7f;
		else if (distanceY >= 2)	catchUpY = 0.8f;
		else						catchUpY = 0.0f;


		if (moveTo.x < cPos.x)moveTo.x += catchUpX;
		else if (moveTo.x > cPos.y)moveTo.x -= catchUpX;
		if (moveTo.y < cPos.y)moveTo.y += catchUpY;
		else if (moveTo.y > cPos.y)moveTo.y -= catchUpY;


		pos.x = cPos.x;
		pos.y = cPos.y;

		XMStoreFloat4x4(&view, XMMatrixTranslation(-pos.x + 360, -pos.y + 240, zoom));



		updateMatrix = false;
	}
	XMMATRIX temp = XMLoadFloat4x4(&view);
	return temp;
}
void Camera::Update(float time) {

	updateMatrix = true;




}

void Camera::Follow(float time) {


	XMMatrixTranslation(origin.x, origin.y, 0);
	Vector2 sc = screenCenter;
	Vector3 s = scale;
	Vector3 o = sc / s;
	origin = o;

}