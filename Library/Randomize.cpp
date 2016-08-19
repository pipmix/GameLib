#include "Randomize.h"

Randomize::Randomize() {


}



double Randomize::GetNormalDist(double x, double y) {

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::normal_distribution<float> distribution(x, y);
	
	return distribution(generator);

}

double Randomize::GetRealDist(double x, double y) {


	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);
	std::uniform_real_distribution<float>  distribution(x, y);
	return distribution(generator);


}


