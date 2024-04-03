#pragma once
#include "Car.h"

enum Weather {
	Rain,
	Snow,
	Sunny
};

class Circuit
{
private:
	int length, nr_cars;
	Car** cars;
	Weather currentWeather;
public:
	Circuit();
	~Circuit();
	void SetLength(int length);
	void AddCar(Car* car);
	void SetWeather(Weather weather);
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
	void Race();
};

