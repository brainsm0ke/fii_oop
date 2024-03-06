#include "Student.h"
#include <iostream>

int main() {
	Student s;
	s.setName("Georgescu George");
	s.setHistoryGrade(6.5f);
	s.setEnglishGrade(7.5f);
	s.setMathGrade(8.0f);
	char n[100];
	s.getName(n);
	std::cout << n << '\n';	
	std::cout << s.getMathGrade() << ' ';
	std::cout << s.getEnglishGrade() << ' ';
	std::cout << s.getHistoryGrade() << " \n";
	std::cout << s.AvgGrade();
}
