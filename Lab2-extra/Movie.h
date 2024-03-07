#pragma once

class Movie {
	char name[257] = {0};
	int year;	
	int length;
	float score;
	
	public:
	void set_name(const char* n);
	void get_name(char* n);

	void set_year(int y);
	int get_year();
	
	void set_length(int l);
	int get_length();
	
	void set_score(float s);
	float get_score();

	int passed_years();
};

