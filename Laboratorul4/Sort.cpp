#include "Sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdarg>
#include <algorithm>

int partition(int *arr, int low, int high, bool ascendent) {
	if (ascendent == true) {
		int pivot = arr[high];
		int i = (low - 1);

		for (int j = low; j <= high; j++)
		{
			if (arr[j] < pivot)
			{	
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
		std::swap(arr[i + 1], arr[high]);
		return (i + 1);
	}
	else {
		int pivot = arr[high];
		int i = (low - 1);

		for (int j = low; j <= high; j++)
		{
			if (arr[j] > pivot)
			{
				i++;
				std::swap(arr[i], arr[j]);
			}
		}
		std::swap(arr[i + 1], arr[high]);
		return (i + 1);
	}
}

Sort::Sort(int count, int min_value, int max_value) {
	this->v = new int[count];
	this->length = count;
	std::srand(std::time(nullptr));

	int random_number; //in aceasta valoare se vor stoca numerele random
	for (int i = 0; i < count; i++) {
		random_number = min_value + std::rand() % (max_value - min_value + 1);
		this->v[i] = random_number;
	}

}

Sort::Sort(int *vector, int count) {
	this->v = new int[count];
	this->length = count;
	for (int i = 0; i < count; i++) {
		this->v[i] = vector[i];
	}
}

Sort::Sort(int count, ...) {
	this->v = new int[count];
	this->length = count;
	va_list args;
	va_start(args, count);
	for (int i = 0; i < count; i++) {
		this->v[i] = va_arg(args, int);
	}
	va_end(args);
}

Sort::Sort(const char* numbers) {
	int cnt = 0;
	this->length = 1;
	while (numbers[cnt])
	{
		if (numbers[cnt] == ',') {
			this->length++;
		}
		cnt++;
	}
	this->v = new int[this->length];
	int nr = 0; //in nr se stocheaza numerele din numbers
	int cnt1 = 0; //cu cnt parcurg sirul numbers
	int cnt2 = 0; //pt numar
	cnt = 0;
	while (numbers[cnt1])
	{
		if (numbers[cnt1] == ',') {
			while (cnt2 != cnt1)
			{
				nr = nr * 10 + (numbers[cnt2] - '0');
				cnt2++;
			}
			//std::cout << nr<<"\n";
			this->v[cnt++] = nr;
			nr = 0;
			cnt2 = cnt1 + 1;
		}
		//std::cout << numbers[cnt1] << " ";
		cnt1++;
	}

	if (cnt2 != cnt1) {
		while (cnt2 != cnt1) {
			nr = nr * 10 + (numbers[cnt2] - '0');
			cnt2++;
		}
		this->v[cnt++] = nr;
	}
}

Sort::Sort() : v(new int[6] {1, 2, 3, 4, 5, 6}) {
}

void Sort::BubbleSort(bool ascendent) {
	if (ascendent == true) {
		bool sort = false;
		do {
			sort = true;
			for (int i = 0; i < this->length - 1; i++) {
				if (this->v[i] > this->v[i + 1]) {
					std::swap(this->v[i], this->v[i + 1]);
					sort = false;
				}
			}
		} while (!sort);
	}
	else {
		bool sort = false;
		do {
			sort = true;
			for (int i = 0; i < this->length - 1; i++) {
				if (this->v[i] < this->v[i + 1]) {
					std::swap(this->v[i], this->v[i + 1]);
					sort = false;
				}
			}
		} while (!sort);
	}
}

void Sort::InsertSort(bool ascendent) {
	int key, j;
	if (ascendent == true) {
		for (int i = 0; i < this->length; i++) {
			key = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] > key)
			{
				this->v[j + 1] = this->v[j];
				j--;
			}
			this->v[j + 1] = key;
		} 
	}
	else {
		for (int i = 0; i < this->length; i++) {
			key = this->v[i];
			j = i - 1;
			while (j >= 0 && this->v[j] < key)
			{
				this->v[j + 1] = this->v[j];
				j--;
			}
			this->v[j + 1] = key;
		}
	}
}

void Sort::QuickSort(int low, int high, bool ascendent) {
	if (low < high) {
		int pivot = partition(this->v, low, high, ascendent);
		QuickSort(low, pivot - 1, ascendent);
		QuickSort(pivot + 1, high, ascendent);
	}
}

int Sort::GetElementsCount() {
	return this->length;
}

int Sort::GetElementFromIndex(int index) {
	if (index < this->length) {
		return this->v[index];
	}
	else {
		std::cout << "Indexul introdus ca parametru nu exista";
		return -1;
	}
}

void Sort::Print() {
	for (int i = 0; i < this->length; i++)
		std::cout << this->v[i] << " ";
}