#include "Sort.h"
#include <iostream>

int main(){
	Sort s1(10,0,1000);
	s1.QuickSort();
	s1.Print();
	Sort s2 = {11, 1, 101, 235, 255, 10, 3002};
	s2.BubbleSort();
	s2.Print();
	int list[7] = {100 , 201, 201, 33, 12, 99, 69};
	Sort s3(7,list);
	s3.InsertSort();
	s3.Print();
	Sort s4(6, 34, 22, 14, 23, 1001, 32);
	s4.Print();
	std::cout << s4.GetElementsCount() << '\n';
	Sort s5("11, 23, 420, 124 , 546, 109");
	s5.Print();
	std::cout << s5.GetElementFromIndex(3) << '\n';
}
