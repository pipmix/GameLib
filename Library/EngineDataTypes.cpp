#include "EngineDataTypes.h"


Location::Location() {}
Location::~Location() {}
Location::Location(int x, int y, int r, std::string s) {
	loc.x = (float)x;
	loc.y = (float)y;
	locRadius = (int)r;
	locName = s;
}
void Location::SetLocation(int x, int y, int r, std::string s) {
	loc.x = (float)x;
	loc.y = (float)y;
	locRadius = (int)r;
	locName = s;
}
Vector2			Location::ReturnLocation() { return loc; }
std::string*	Location::ReturnString() { return &locName; }