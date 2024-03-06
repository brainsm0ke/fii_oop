#include "Student.h"
#include <cstring>

Student::Student() {
	strcpy(name,"\0");
	MathGrade = 0;
	EnglishGrade = 0;
	HistoryGrade = 0;
}

void Student::setName(const char n[]){
	strncpy(name,n,100);
}

void Student::getName(char n[]){
	strncpy(n,name,100);
}

void Student::setMathGrade(float g){
	MathGrade = g;
}

float Student::getMathGrade(){
	return MathGrade;
}

void Student::setEnglishGrade(float g){
	EnglishGrade = g;
}

float Student::getEnglishGrade(){
	return EnglishGrade;
}

void Student::setHistoryGrade(float g){
	HistoryGrade = g;
}

float Student::getHistoryGrade(){
	return HistoryGrade;
}

float Student::AvgGrade(){
	return (MathGrade+EnglishGrade+HistoryGrade)/3;
}
