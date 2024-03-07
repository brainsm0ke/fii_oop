#include "MovieSeries.h"
#include <stdexcept>
#include <iostream>

void MovieSeries::init(){
	count = 0;
}

void MovieSeries::add(Movie* m){
	if(count < 16) movies[count] = m;
	else throw std::overflow_error("Overflow from MovieSeries class");
	count++;
}

void MovieSeries::print(){
	char name[257];
	Movie* m;
	for(int i = 0; i < count; i++){
		m = movies[i];
		m->get_name(name);
		std::cout << "Name: \"" << name << "\""
			<< " | Year: " << m->get_year()
			<< " | Passed years: " << m->passed_years()
			<< " | Length: " << m->get_length()
			<< " | IMDB score: " << m->get_score() << '\n';
	}
}

void MovieSeries::sort(){
	Movie* m;
	bool ok;
	int j = 1;
	do{
		ok = true;
		for(int i=0; i<count-j; i++){
			if(movies[i]->passed_years() > movies[i+1]->passed_years()){
				ok = false;
				m = movies[i];
				movies[i] = movies[i+1];
				movies[i+1] = m;
			}
		}
		j++;
	}while(!ok);
}
