#include "Circuit.h"
#include <iostream>

Circuit::Circuit() {
	this->nr_cars = 0;
	this->length = 0;
	this->cars = new Car*[5];
	this->currentWeather = Sunny;
}

Circuit::~Circuit() {
	delete[] this->cars;
}

void Circuit::SetLength(int length) {
	this->length = length;
}

void Circuit::AddCar(Car* car) {
	this->nr_cars++;
	this->cars[this->nr_cars - 1] = car;
	if (this->currentWeather == Snow) {
		this->cars[this->nr_cars - 1]->speed = car->as_snow;
	}
	else if (this->currentWeather == Rain) {
		this->cars[this->nr_cars - 1]->speed = car->as_rain;
	}
	else {
		this->cars[this->nr_cars - 1]->speed = car->as_sunny;
	}
}

void Circuit::SetWeather(Weather weather) {
	this->currentWeather = weather;
}

void Circuit::Race() {
	for (int i = 0; i < this->nr_cars; i++) {
		this->cars[i]->fuel_capacity = this->cars[i]->fuel_capacity - this->cars[i]->fuel_consumption;
	}
}

void Circuit::ShowFinalRanks() {
	bool sort;
	do {
		sort = true;
		for (int i = 0; i < this->nr_cars - 1; i++) {
			//std::cout << this->cars[i]->speed << " " << this->cars[i + 1]->speed << "\n";
			if ((float)this->length / (float)this->cars[i]->speed > (float)(this->length / (float)this->cars[i + 1]->speed)) {
				std::cout << (float)this->length / (float)this->cars[i]->speed << " " << (float)(this->length / (float)this->cars[i + 1]->speed) << "\n";
				std::swap(this->cars[i], this->cars[i + 1]);
				sort = false;
			}
		}
	} while (!sort);
	for (int i = 0; i < this->nr_cars; i++) {
		std::cout <<i + 1 <<" : " << this->cars[i]->name << "\n";
	}
}



void Circuit::ShowWhoDidNotFinish() {
	for (int i = 0; i < this->nr_cars; i++) {
		if (this->cars[i]->fuel_capacity < 0) {
			std::cout<<this->cars[nr_cars]->name<< " DNF" << "\n";
		}
	}
}