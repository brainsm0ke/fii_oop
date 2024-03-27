#include "Number.h"
#include <cstdint>
#include <iostream>
#include <stdexcept>

Number::Number(const char* value, int base)
	:b(base), num(0){
	for(int i=0; value[i] != '\0'; i++){
		num *= b;
		if(value[i] >= '0' && value[i] <= '9')
			num += value[i] - '0';
		else if(value[i] >= 'A' && value[i] <= 'F')
			num += value[i] - 'A' + 10;
	}

}

Number::Number(Number& value):b(value.b), num(value.num){}

Number::Number(Number&& value):b(value.b), num(value.num){
	value.b = 0;
}

Number::Number(uint32_t n):b(10),num(n){}

Number::~Number(){}

Number& Number::operator=(uint32_t value){
	num = value;
	return *this;
}

Number& Number::operator=(const char* value){
	num = 0;
	if(b == 0) throw std::runtime_error("Number is null!");
	else{
		for(int i=0; value[i] != '\0'; i++){
			num *= b;
			if(value[i] >= '0' && value[i] <= '9')
				num += value[i] - '0';
			else if(value[i] >= 'A' && value[i] <= 'F')
				num += value[i] - 'A' + 10;
		}
	}
	return *this;
}

Number& Number::operator=(Number& value){
	b = value.b;
	num = value.num;
	return *this;
}

Number& Number::operator=(Number&& value){
	b = value.b;
	num = value.num;
	value.b = 0;
	return *this;
}

char Number::operator[](uint32_t index){
	if(b == 0){
		throw std::runtime_error("Number is null!");
	}
	else{
		uint32_t h = 1;
		while(h <= num/b) h *= b;
		for(uint32_t i=0; i<index; i++) h /= b;
		if(h == 0){
			throw std::range_error("Index out of range!");
		}
		uint8_t c = (num / h) % b;
		if(c < 10) return '0'+c;
		else return 'A' + c - 10;
	}
}

bool Number::operator<(const Number& lhs){
	if(b == 0) std::cout << "Number is null!";
	if(num < lhs.num) return true;
	else return false;
}

bool Number::operator>(const Number& lhs){
	if(b == 0) std::cout << "Number is null!";
	if(num > lhs.num) return true;
	else return false;
}

bool Number::operator==(const Number& lhs){
	if(b == 0) std::cout << "Number is null!";
	if(num == lhs.num) return true;
	else return false;
}

bool Number::operator!=(const Number& lhs){
	if(b == 0) std::cout << "Number is null!";
	if(num != lhs.num) return true;
	else return false;
}

bool Number::operator<=(const Number& lhs){
	if(b == 0) std::cout << "Number is null!";
	if(num <= lhs.num) return true;
	else return false;
}

bool Number::operator>=(const Number& lhs){
	if(b == 0) std::cout << "Number is null!";
	if(num >= lhs.num) return true;
	else return false;
}

Number& Number::operator--(){
	if(b == 0) std::cout << "Number is null!";
	uint32_t h = 1;
	while(h <= num/b) h *= b;
	num = num%h;
	return *this;
}

Number Number::operator--(int){
	num /= b;
	return *this;
}

Number operator+(const Number& rhs, const Number& lhs){
	Number n("",0);
	if(rhs.b > lhs.b) n.b = rhs.b;
	else n.b = lhs.b;
	n.num = lhs.num + rhs.num;
	return n;
}

Number operator-(const Number& rhs, const Number& lhs){
	Number n("",0);
	if(rhs.b > lhs.b) n.b = rhs.b;
	else n.b = lhs.b;
	n.num = uint32_t(lhs.num - rhs.num);
	return n;
}

void Number::SwitchBase(int newBase){
	b = newBase;
}

Number Number::operator+=(const Number& lhs){
	*this = *this + lhs;
	return *this;
}

Number Number::operator-=(const Number& lhs){
	*this = *this - lhs;
	return *this;
}

void Number::Print(){
	if(b == 0) std::cout << "Number is null!";
	else{
		uint32_t h = 1;
		while(h <= num/b) h *= b;
		while(h){
			uint8_t c = (num / h) % b;
			if(c < 10) std::cout << char('0'+c);
			else std::cout << char('A' + c - 10);
			h /= b;
		}
		std::cout << '\n';
	}
}

int Number::GetDigitsCount(){
	if(b == 0) std::cout << "Number is null!";
	uint32_t n = num;
	int i = 0;
	while(n){
		i++;
		n /= b;
	}
	return i;
}

int Number::GetBase() {return b;};
