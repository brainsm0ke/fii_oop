#include "Math.h"
#include <iostream>

int main(){
	Math m;
	std::cout << m.Add(1,2) << ' ';
	std::cout << m.Add(1,2,3) << ' ';
	std::cout << m.Add(1.0, 1.5) << ' ';
	std::cout << m.Add(1.0, 1.5, 2.6) << '\n';
	std::cout << m.Mul(3,2) << ' ';
	std::cout << m.Mul(3,2,4) << ' ';
	std::cout << m.Mul(1.0,2.3) << ' ';
	std::cout << m.Mul(1.0,2.3,3.2) << '\n';
	std::cout << m.Add(5, 1, 2, 3, 4, 5) << '\n';
	char* s = m.Add("123","999");
	std::cout << s;
	delete[] s;
}
