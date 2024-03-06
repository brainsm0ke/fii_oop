#pragma once

class Student {
	char name[100];
	float MathGrade;
	float EnglishGrade;
	float HistoryGrade;

	public:
	Student();

	void setName(const char n[]);
	void getName(char n[]);

	void setMathGrade(float g);
	float getMathGrade();
	
	void setEnglishGrade(float g);
	float getEnglishGrade();

	void setHistoryGrade(float g);
	float getHistoryGrade();

	float AvgGrade();
};
