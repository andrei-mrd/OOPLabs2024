#pragma once
#include <iostream>

template <class T>
class Vector {
private:
	T* arr;
	int size;
public:
	Vector() {
		this->arr = nullptr;
		this->size = 0;
	}
	
	Vector(Vector& v) {
		this->size = v.size;
		delete[] this->arr;
		this->arr = new T[v.size];
		for (int i = 0; i < v.size; i++) {
			this->arr[i] = v.arr[i];
		}
	}

	Vector(Vector&& v) {
		this->size = v.size;
		delete[] this->arr;
		this->arr = new T[v.size + 1];
		this->arr = v.arr;
	}

	void insert(int index, const T& element) {
		int i = 0;
		T v[100];
		while (i < this->size)
		{
			v[i] = this->arr[i];
			i++;
		}
		delete[] this->arr;
		this->arr = new T[this->size + 1];
		i = 0;
		while (i < this->size)
		{
			this->arr[i] = v[i]; 
			i++;
		}
		this->arr[this->size] = element;
		this->size++;
	}

	void remove(int index) {
		int i = index;
		while (i < this->size - 1) {
			this->arr[i] = this->arr[i + 1];
			i++;
		}
		this->size--;
	}

	void sort(int (*callback)(T, T)) {
		for (int i = 0; i < this->size - 1; i++) {
			for (int j = i + 1; j < this->size; j++) {
				if (callback != nullptr) {
					if (callback(this->arr[i], this->arr[j]) == 1) {
						std::swap(this->arr[i], this->arr[j]);
					}
				}
				else {
					if (this->arr[i] > this->arr[j]) {
						std::swap(this->arr[i], this->arr[j]);
					}
				}
			}
		}
	}

	void print() {
		for (int i = 0; i < this->size; i++) {
			std::cout << this->arr[i] << " ";
		}
		std::cout << "\n";
	}

	T operator[](int index) {
		return this->arr[index];
	}

	~Vector() {
		delete[] this->arr;
	}
};
