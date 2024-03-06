#include "NumberList.h"
#include <iostream>

void NumberList::Init() {
	count = 0;
}

bool NumberList::Add(int x){
	if(count >= 10) return false;
	count++;
	numbers[count-1] = x;
	return true;
}

void NumberList::Sort() {
	bool ok;
	do{
		ok = 1;
		for(int i=0; i<count-1; i++){
			if(numbers[i] > numbers[i+1]){
				int t = numbers[i];
				numbers[i] = numbers[i+1];
				numbers[i+1] = t;
				ok = 0;
				break;
			}
		}
	}while(!ok);
}

void NumberList::Print() {
	for(int i=0; i < count; i++) std::cout << numbers[i] << ' ';
	std::cout << '\n';
}
