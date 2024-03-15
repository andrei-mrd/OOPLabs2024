#include "Canvas.h"
#include <iostream>

int main() {
	Canvas obj1(100, 100);
	obj1.DrawCircle(10, 10, 10, '*');
	obj1.FillCircle(10, 10, 10, '*');
	obj1.DrawRect(20, 20, 40, 40, '*');
	obj1.FillRect(20, 20, 40, 40, '*');
	obj1.SetPoint(45, 45, '*');
	obj1.DrawLine(50, 50, 60, 60, '*');
	obj1.Print();
	obj1.Clear();

	return 0;
}