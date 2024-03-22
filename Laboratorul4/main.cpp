#include <iostream>
#include "Sort.h"

int main() {
	std::cout << "obiectul 1" << "\n";
	Sort obj1("60,20,30,90,10"); //char *
	obj1.QuickSort(0, obj1.GetElementsCount() - 1, false);
	obj1.Print();
	std::cout << "\n";
	std::cout<<obj1.GetElementFromIndex(3)<<"\n";
	std::cout << obj1.GetElementsCount() << "\n";

	std::cout << "obiectul 2" << "\n";
	Sort obj2(5, 1, 9); //count, min value, max value
	obj2.BubbleSort(true);
	obj2.Print();
	std::cout << "\n";

	std::cout << "obiectul 3" << "\n";
	Sort obj3(5, 2, 4, 1, 3, 7); //count ...
	obj3.InsertSort(true);
	obj3.Print();
	std::cout << "\n";

	std::cout << "obiectul 4" << "\n";
	int* v = new int[5] {1, 2, 9, 0, 4};
	Sort obj4(v, 5);
	obj4.Print();
	std::cout << "\n";

	
	return 0;
}