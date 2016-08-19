#pragma once
#include <windows.h>
#include <DirectXMath.h>
#include <string>

using namespace DirectX;


class Location {
public:
	Location();
	Location(int, int, int, std::string);
	~Location();
	XMFLOAT2				ReturnLocation();
	std::string*		ReturnString();
	void				SetLocation(int, int, int, std::string);
private:
	XMFLOAT2				loc;
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
