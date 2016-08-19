#pragma once
#include <windows.h>
#include <DirectXMath.h>
#include <cmath>
using namespace DirectX;


extern HWND hWnd;

class Camera {
public:
	Camera();

	XMMATRIX 	transformMatrix(XMFLOAT2& p);
	void		Update(float time);
	void		Follow(float time);



private:


	float		FOV;
	float		aspectRatio;
	float		nearPlane;
	float		farPlane;
	float		zoom;
	float		speed;



	XMFLOAT3	pos;
	XMFLOAT3	rot;
	XMFLOAT3	lookAt;
	XMFLOAT3	up;


	XMFLOAT4X4	cameraMatrix;
	XMFLOAT4X4	screenMatrix;
	XMFLOAT4X4	view;
	XMFLOAT4X4	cameraScreenMatrix;



	XMFLOAT3		inputDirection;
	XMFLOAT3		origin;
	XMFLOAT3		scale;


	XMFLOAT2 screenCenter;
	bool		updateMatrix;


	int viewportHeight;
	int viewportWidth;

	XMFLOAT3 moveTo;
	XMFLOAT3 currentPos;


};