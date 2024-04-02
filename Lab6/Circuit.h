#pragma once

#include "Car.h"
#include "Weather.h"
#include <vector>

class Circuit {
	std::vector<Car*> cars;
	std::vector<float> carRanks;
	int carCount;
	Weather weather;
	float length;
	public:
	Circuit();
	~Circuit();
	void SetLength(float l);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};
