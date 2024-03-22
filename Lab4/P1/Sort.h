#pragma once
#include <vector>
#include <initializer_list>

class Sort
{
	std::vector<int> v;
	void RecQuickSort(bool ascendent,unsigned int a, unsigned int b);
public:
    Sort(const unsigned int l,int min, int max);
    Sort(std::initializer_list<int> list);
    Sort(const unsigned int l, int list[]);
    Sort(const unsigned int l, ...);
    Sort(const char* c);
    void InsertSort(bool ascendent=false);
    void QuickSort(bool ascendent=false);
    void BubbleSort(bool ascendent=false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
