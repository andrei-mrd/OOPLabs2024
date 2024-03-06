#include <iostream>
#include "NumberList.h"
using namespace std;

int main()
{
	NumberList myObj;
	myObj.Init();
	myObj.Add(25);
	myObj.Add(21);
	myObj.Add(28);
	myObj.Sort();
	myObj.Print();


	return 0;
}