#include "GlobalFunctions.h"
#include "Student.h"
#include <cstring>

int compareNames(Student first, Student second){
	char n[100], m[100];
	first.getName(n);
	second.getName(m);
	int diff = strcmp(n,m);
	if(diff > 0) return 1;
	else if(diff < 0) return -1;
	else return 0;
}

int compareMathGrades(Student first, Student second){
	float diff = first.getMathGrade() - second.getMathGrade();
	if(diff > 0) return 1;
	else if(diff < 0) return -1;
	else return 0;
}

int compareEnglishGrades(Student first, Student second){
	float diff = first.getEnglishGrade() - second.getEnglishGrade();
	if(diff > 0) return 1;
	else if(diff < 0) return -1;
	else return 0;
}


int compareHistoryGrades(Student first, Student second){
	float diff = first.getHistoryGrade() - second.getHistoryGrade();
	if(diff > 0) return 1;
	else if(diff < 0) return -1;
	else return 0;
}

int compareAvgGrades(Student first, Student second){
	float diff = first.AvgGrade() - second.AvgGrade();
	if(diff > 0) return 1;
	else if(diff < 0) return -1;
	else return 0;
}
