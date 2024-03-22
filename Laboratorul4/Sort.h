#pragma once
class Sort
{
	//add data members
	int length = 0;
	int *v;
public:
	//add constructors
	Sort(int count, int min_value, int max_value);
	Sort();
	Sort(int* vector, int size);
	Sort(int count, ...);
	Sort(const char* numbers);
	void InsertSort(bool ascendent = false);
	void QuickSort(int low, int high, bool ascendent = false);
	void BubbleSort(bool ascendent = false);
	void Print();
	int GetElementsCount();
	int GetElementFromIndex(int index);
};

