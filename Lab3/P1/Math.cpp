#include "Math.h"
#include <cstdarg>
#include <cstring>
#include <iostream>

int Math::Add(int a, int b){
	return a+b;
}

int Math::Add(int a, int b, int c){
	return a+b+c;
}

int Math::Add(double a, double b){
	return a+b;
}

int Math::Add(double a, double b, double c){
	return a+b+c;
}

int Math::Mul(int a, int b){
	return a*b;
}

int Math::Mul(int a, int b, int c){
	return a*b*c;
}

int Math::Mul(double a, double b){
	return a*b;
}

int Math::Mul(double a, double b, double c){
	return a*b*c;
}

int Math::Add(int count, ...){
	va_list args;
	int n = 0;
	va_start(args,count);
	for(int i=0; i<count; i++){
		n += va_arg(args,int);
	}
	va_end(args);
	return n;
}

char* Math::Add(const char* a, const char* b){
	if(a == nullptr || b == nullptr) return nullptr;
	if(strlen(a) > strlen(b)){
		const char* tmp = a;
		a = b;
		b = tmp;
	}
	unsigned long i, alen = strlen(a), blen = strlen(b);
	unsigned int r = 0;
	char* s = new char[blen+2];
	for(i=0; i<alen; i++){
		r = a[alen-1-i] + b[blen-1-i] - 2*'0';
		s[i] = r%10 + '0';
		r /= 10;
	}
	for(i; i<blen; i++){
		r = b[blen-1-i] - '0';
		s[i] = r%10 + '0';
		r /= 10;
	}
	if(r>0) {s[i] = r + '0';}
	else i--;
	char t;
	for(int j=0; j<=i/2; j++){
		t = s[j];
		s[j] = s[i-j];
		s[i-j] = t;
	}
	s[i+1] = '\0';
	return s;
}
