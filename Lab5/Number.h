#pragma once
#include <cstdint>

class Number
{
	uint64_t num;
	uint8_t b;
public:
   Number(const char * value, int base); // where base is between 2 and 16
   Number(Number& value);
   Number(Number&& value);
   Number(uint32_t n);
   ~Number();
   Number& operator=(uint32_t value);
   Number& operator=(const char* value);
   Number& operator=(Number& value);
   Number& operator=(Number&& value);
   char operator[](uint32_t index);
   bool operator<(const Number& lhs);
   bool operator>(const Number& lhs);
   bool operator==(const Number& lhs);
   bool operator!=(const Number& lhs);
   bool operator<=(const Number& lhs);
   bool operator>=(const Number& lhs);
   Number& operator--();
   Number operator--(int);
   friend Number operator+(const Number& rhs, const Number& lhs);
   friend Number operator-(const Number& rhs, const Number& lhs);
   Number operator+=(const Number& lhs);
   Number operator-=(const Number& lhs);
   void SwitchBase(int newBase);
   void Print();
   int  GetDigitsCount(); // returns the number of digits for the current number
   int  GetBase(); // returns the current base
};
