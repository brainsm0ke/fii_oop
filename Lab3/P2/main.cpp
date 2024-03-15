#include "Canvas.h"
#include <iostream>

int main(){
	Canvas canv(10,10);

	canv.DrawCircle(4,4,4,'c');
	canv.SetPoint(4,4,'p');
	canv.Print();
	std::cout << '\n';
	canv.Clear();

	canv.FillCircle(4,4,4,'c');
	canv.Print();
	std::cout << '\n';
	canv.Clear();

	canv.DrawRect(0,0,9,9,'s');
	canv.DrawLine(0,0,4,4,'s');
	canv.DrawLine(9,9,4,4,'s');
	canv.DrawLine(9,0,5,4,'s');
	canv.DrawLine(0,9,5,4,'s');
	canv.Print();
	std::cout << '\n';
	canv.Clear();

	canv.FillRect(2,2,7,7,'s');
	canv.Print();

	return 0;
}
