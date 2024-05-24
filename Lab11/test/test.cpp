#include <cstdlib>
#include <gtest/gtest.h>
#include <Sort.h>

TEST(SortTest, Sorted){
	srand(time(nullptr));
	int a[1000];
	for(auto x: a){
		x = rand();
	}
	sorting_algorithm(a, 1000);
	for(int i=0; i<999; i++){
		ASSERT_LE(a[i],a[i+1]);
	}
}

TEST(SortTest, Swap){
	int i = 10, j = 20;
	swapper(i,j);
	ASSERT_EQ(i,20);
	ASSERT_EQ(j,10);
}

TEST(SortTest, Overflow){
	srand(time(nullptr));
	int a[100] = {0};
	for(int i=0; i<50; i++){
		a[i] = rand();
	}
	sorting_algorithm(a, 50);
	for(int i=50; i<100; i++){
		ASSERT_EQ(a[i],0);
	}
}

TEST(SortTest, NotSortedBackwards){
	srand(time(nullptr));
	int a[1000];
	for(auto x: a){
		x = rand();
	}
	sorting_algorithm(a, 1000);
	bool SortedBackwards = true;
	for(int i=0; i<999; i++){
		if(a[i] < a[i+1]) SortedBackwards = false;
	}
	ASSERT_EQ(SortedBackwards,false);
}
