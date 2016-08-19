#pragma once
#include <random>
#include <chrono>

class Randomize {
public:

	Randomize();

	double GetNormalDist(double x, double y);
	double GetRealDist(double x, double y);


	//int GetNormalDistInt(int x, int y);
	//int GetIntDist(int x, int y);



};