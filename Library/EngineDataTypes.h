#pragma once
#include "../stdafx.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

class Location {
public:
	Location();
	Location(int, int, int, std::string);
	~Location();
	Vector2				ReturnLocation();
	std::string*		ReturnString();
	void				SetLocation(int, int, int, std::string);
private:
	Vector2				loc;
	std::string			locName;
	int					locRadius;
};

class DataRect {


public:

	RECT rect;
	std::string info;


};

struct CIRC{
	LONG    x;
	LONG    y;
	LONG    rad;

};

