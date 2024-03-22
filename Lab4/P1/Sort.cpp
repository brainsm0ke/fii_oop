#include "Sort.h"
#include <cstdarg>
#include <initializer_list>
#include <malloc/_malloc.h>
#include <random>
#include <vector>
#include <iostream>

Sort::Sort(const unsigned int l, int min, int max){
	v = std::vector<int>(l);
	std::random_device rd;
	std::uniform_int_distribution uniform(min,max);
	for(auto& x : v){
		x = uniform(rd);
	}
}

Sort::Sort(std::initializer_list<int> list){
	v = std::vector<int>(list.size());
	for(int i=0; i<list.size(); i++){
		v[i] = *(list.begin() + i);
	}
}

Sort::Sort(const unsigned int l, int list[]){
	v = std::vector<int>(l);
	for(int i=0; i<v.size(); i++){
		v[i] = list[i];
	}
}

Sort::Sort(const unsigned int l, ...) {
		v = std::vector<int>(l);
		va_list args;
		va_start(args,l);
		for(int i=0; i<v.size(); i++){
			v[i] = va_arg(args,int);
		}
		va_end(args);
	}

Sort::Sort(const char* c){
	unsigned int l = 1;
	for(int i=0; c[i] != '\0'; i++){
		if(c[i] == ','){
			l++;
		}
	}
	v = std::vector<int>(l);
	int n = 0;
	int k = 0;
	for(int i=0; c[i] != '\0'; i++){
		if(c[i] == ','){
			v[k] = n;
			++k;
			n = 0;
		} else if (c[i] >= '0' && c[i] <= '9'){
			n = n*10 + (c[i] - '0');
		} else if(c[i] == '-'){
			n = -n;
		}
	}
	v[k] = n;
}

void Sort::InsertSort(bool ascendent){
	for(int i=1; i<v.size(); i++){
		for(int j=i; j > 0; j--){
			int s = 1;
			if(ascendent == false) s = -1;
			int res = (v[j]-v[j-1])*s;
			if(res > 0) break;
			int t = v[j];
			v[j] = v[j-1];
			v[j-1] = t;
		}
	}
}

void Sort::QuickSort(bool ascendent){
	RecQuickSort(ascendent, 0, v.size()-1);
}

void Sort::RecQuickSort(bool ascendent, unsigned int a,unsigned int b){
	if(a < b){
		std::random_device rd;
		std::uniform_int_distribution u(a,b);
		unsigned int m = u(rd);
		unsigned int x = a, y = b, e = a;
		int s, pivot = v[m];
		if(ascendent == true) s = 1;
		else s = -1;
		while(e<=y){
			int res = (pivot-v[e])*s;
			if(res > 0){
				int t = v[x];
				v[x] = v[e];
				v[e] = t;
				x++;
				e++;
			}
			else if(res < 0){
				int t = v[y];
				v[y] = v[e];
				v[e] = t;
				y--;
			}
			else if(res == 0){
				e++;
			}
		}
		RecQuickSort(ascendent,a,x);
		RecQuickSort(ascendent,y+1,b);
	}
}

void Sort::BubbleSort(bool ascendent){
	int s;
	if(ascendent == false) s = -1;
	else s = 1;
	for(int i=0; i<v.size(); i++){
		for(int j=1; j<v.size()-i; j++){
			int res = (v[j-1]-v[j])*s;
			if(res > 0){
				int t = v[j];
				v[j] = v[j-1];
				v[j-1] = t;
			}
		}
	}
}

int Sort::GetElementsCount(){
	return v.size();
}

int Sort::GetElementFromIndex(int index){
	return v[index];
}

void Sort::Print(){
	for(auto x : v){
		std::cout << x << ' ';
	}
	std::cout << '\n';
}
