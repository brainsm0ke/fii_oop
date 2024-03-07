#include "Movie.h"
#include <cstring>
#include <ctime>

void Movie::set_name(const char* n){
	strncpy(name,n,256);
}

void Movie::get_name(char* n){
	strncpy(n,name,256);
}

void Movie::set_year(int y){
	year = y;
}

int Movie::get_year(){
	return year;
}

void Movie::set_length(int l){
	length = l;
}

int Movie::get_length() {
	return length;
}

void Movie::set_score(float s){
	score = s;
}

float Movie::get_score(){
	return score;
}

int Movie::passed_years() {
	time_t current_time = time(nullptr);
	int current_year = localtime(&current_time)->tm_year;
	return 1900 + current_year - year;
}
