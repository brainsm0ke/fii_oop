#include "GlobalFunctions.h"
#include "Movie.h"
#include <cstring>

int movie_compare_name(Movie first, Movie second){
	char n[257], m[257];
	first.get_name(n);
	second.get_name(m);
	int diff = strcmp(n,m);
	if(diff > 0) return 1;
	if(diff < 0) return -1;
	else return 0;
}

int movie_compare_year(Movie first, Movie second){
	int diff = first.get_year() - second.get_year();
	if(diff > 0) return 1;
	if(diff < 0) return -1;
	else return 0;
}

int movie_compare_score(Movie first, Movie second){
	float diff = first.get_score() - second.get_score();
	if(diff > 0) return 1;
	if(diff < 0) return -1;
	else return 0;
}

int movie_compare_length(Movie first, Movie second){
	int diff = first.get_length() - second.get_length();
	if(diff > 0) return 1;
	if(diff < 0) return -1;
	else return 0;
}

int movie_compare_passed_years(Movie first, Movie second){
	int diff = first.passed_years() - second.passed_years();
	if(diff > 0) return 1;
	if(diff < 0) return -1;
	else return 0;
}
