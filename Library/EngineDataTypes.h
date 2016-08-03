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

class Animation {

public:
	std::string name;
	int noFrames;
	int startFrame;
	float speed;
	bool loop;
};


struct Moves {

	bool left = 0;
	bool right = 0;
	bool up = 0;
	bool down = 0;

	bool jump = 0;
	bool activate = 0;
	bool attack = 0;
	bool start = 0;


};
