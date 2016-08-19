#pragma once

#include <windows.h>

#include <d3d11_1.h>
#include <DirectXMath.h>
#include <SimpleMath.h>



#pragma comment (lib, "d3d11.lib")

using namespace DirectX;
using namespace DirectX::SimpleMath;


#define F1 float
#define F2 XMFLOAT2
#define F3 XMFLOAT3
#define V XMVECTOR

namespace Util {

	F2 BasicTween(F2& position, F2 target, F1 ease);
	F2 GetDistanceVector2d(F2 position, F2 target);


	int GetTileMapIndex(int x, int y);


	bool CollidePointRect(XMFLOAT2 point, RECT& r);
	bool CollidePointRect(int x, int y, RECT& r);
	bool NumberInRange(int num, int minNum, int maxNum);



	struct PPOINT {
		int x;
		int y;
		PPOINT(int xx, int yy) : x(xx), y(yy) {};
		/*
		union x
		{
			float X;
			int X;
		};
		union y
		{
			float Y;
			int Y;
		};
		*/
	};




	float GetAngle(XMFLOAT2& velocity);
	float GetLength(XMFLOAT2& vector);


	void SetLength(XMFLOAT2& velocity, float length);
	void SetAngle(XMFLOAT2& vector, float angle);


	void Add(XMFLOAT2& dest, XMFLOAT2 source);
	void Subtract(XMFLOAT2& dest, XMFLOAT2 source);

	//void Acceleration()
}