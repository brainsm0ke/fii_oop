#include "NumberList.h"

int main(){
	NumberList n;
	n.Init();
	n.Add(10);
	n.Print();
	n.Add(20);
	n.Add(5);
	n.Add(15);
	n.Sort();
	n.Print();
	while(n.Add(99));
	n.Print();
}
