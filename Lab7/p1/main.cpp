long double operator""_Kelvin(long double x){
	return x - 275.15;
}

long double operator""_Kelvin(unsigned long long x){
	return x - 275.15;
}

long double operator""_Fahrenheit(long double x){
	return (x-32)/1.8;
}

long double operator""_Fahrenheit(unsigned long long x){
	return (x-32)/1.8;
}

int main() {
	float a = 300_Kelvin; // convert to Celsius from a integer literal
	float b = 120_Fahrenheit; // same as below
	float c = 200.14_Kelvin; // you can also use floating point literal
	return 0;
}
