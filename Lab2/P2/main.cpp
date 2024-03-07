#include "Student.h"
#include "GlobalFunctions.h"
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
	std::cout << s.AvgGrade() << '\n';

	Student s2;
	s2.setName("Maslinescu Marius");
	s2.setMathGrade(8.0f);
	s2.setEnglishGrade(6.5f);
	s2.setHistoryGrade(7.5f);

	std::cout << compareNames(s,s2) << ' '
		<< compareMathGrades(s,s2) << ' '
		<< compareEnglishGrades(s,s2) << ' '
		<< compareHistoryGrades(s,s2) << ' '
		<< compareAvgGrades(s,s2);
}
