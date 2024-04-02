#include "Circuit.h"
#include "Weather.h"
#include <iostream>
#include <stdexcept>
#include <vector>

Circuit::Circuit() {
	cars = std::vector<Car*>();
	carRanks = std::vector<float>();
	carCount = 0;
	weather = Weather::Sunny;
	length = 0;
}

Circuit::~Circuit(){
	for(int i=0; i<carCount; i++){
		delete cars[i];
	}
}

void Circuit::SetLength(float l){
	length = l;
}

void Circuit::SetWeather(Weather w){
	weather = w;
}

void Circuit::AddCar(Car* car){
	cars.push_back(car);
	carRanks.push_back(0);
	carCount++;
}

void Circuit::Race(){
	if(carCount == 0) throw std::runtime_error("Circuit is empty!");
	for(int i=0; i<carCount; i++){
		if((cars[i]->FuelCapacity/cars[i]->FuelConsumption)*100
				>= length){
			switch(weather){
				case Weather::Sunny:
					carRanks[i] = length / cars[i]->AvgSpeedSunny;
					break;
				case Weather::Rain:
					carRanks[i] = length / cars[i]->AvgSpeedRain;
					break;
				case Weather::Snow:
					carRanks[i] = length / cars[i]->AvgSpeedSnow;
					break;
			}
		} else carRanks[i] = 0;
	}
}

void Circuit::ShowFinalRanks(){
	std::cout << "Final Ranks:\n";
	if(carCount == 0) throw std::runtime_error("Circuit is empty!");
	std::vector<int> freq(carCount, 0);
	for(int i=0; i<carCount; i++){
		int m = 0;
		for(int j=0; j<carCount; j++){
			if(freq[j] == 0){
				if(freq[m] == 1){
					m = j;
				} else if (carRanks[m] > carRanks[j]){
					m = j;
				}
			}
		}
		int hours = int(carRanks[m]);
		int minutes = int((carRanks[m] - float(hours)) * 60);
		std::cout << i+1 << ". Car #" << m << ": ";
		if(hours != 0) std::cout << hours << " hours ";
		if(minutes != 0) std::cout << minutes << " minutes";
		std::cout << '\n';
		freq[m] = 1;
	}
}

void Circuit::ShowWhoDidNotFinish(){
	for(int i=0; i<carCount; i++){
		if(carRanks[i] == 0) std::cout << "Car " << i 
			<< " ran out of fuel.\n";
	}
}
