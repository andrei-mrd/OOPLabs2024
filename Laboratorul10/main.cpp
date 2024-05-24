#include <iostream>
#include <stdio.h>
#include <exception>
#include <string>
using namespace std;

class Array_out_of_range : public exception {
public:
    virtual const char* what() const throw() {
        return "Index invalid";
    }
};

class Array_out_of_space : public exception {
public:
    virtual const char* what() const throw() {
        return "Array-ul nu are suficient spatiu alocat";
    }
};

class Array_memory_coruption : public exception {
public:
    virtual const char* what() const throw() {
        return "Incerci sa stergi un nullptr !";
    }
};

void resizeMessage(int size, int capacity) {
    printf("Array-ul s-a redimensionat si acum are size : %d, capacitate : %d \n", size, capacity);
}

class Array;

class ArrayIterator {
private:
    int current;
    int** arr;
public:
    ArrayIterator():arr(nullptr), current(0){}
    ArrayIterator(const ArrayIterator& other, const int& current) {
        this->arr = other.arr;
        this->current = current;
    }
    ArrayIterator(int ** array, int curr):arr(array), current(curr){}
    ArrayIterator& operator ++() {
        this->current++;
        return *this;
    }

    ArrayIterator& operator --() {
        this->current--;
        return *this;
    }

    bool operator!=(const ArrayIterator& other) const {
        return this->arr != other.arr || this->current != other.current;
    }

    int& GetElement() {
        return *this->arr[current];
    }
};

class Array
{
private:
    int** list;
    int size;
    int capacity;

public:
    Array() {
        this->list = nullptr;
        this->size = 0;
        this->capacity = 0;
    }

    Array(int capacity) {
        this->list = new int* [capacity];
        for (int i = 0; i < capacity; i++)
            this->list[i] = nullptr;
        this->size = 0;
        this->capacity = capacity;
    }

    ~Array() {
        for (int i = 0; i < this->capacity; i++)
            if(this->list[i] != nullptr)
                delete this->list[i];
        delete[] this->list;
        this->size = 0;
        this->capacity = 0;
    }

    Array(const Array& otherArray) {
        this->list = new int* [otherArray.capacity];
        this->size = otherArray.size;
        this->capacity = otherArray.capacity;
        for (int i = 0; i < this->capacity; i++) {
            if (otherArray.list[i] == nullptr)
                this->list[i] = nullptr;
            else{
                this->list[i] = new int;
                *this->list[i] = *otherArray.list[i];
            }
                
        }
    }

    int& operator[](int index) {
        if (index < 0 || index >= this->size) {
            throw Array_out_of_range();
        }
        return *this->list[index];
    }

    const Array& operator +=(const int& newElement) {
        if (this->size < this->capacity) {
            this->list[this->size] = new int;
            *this->list[this->size] = newElement;
            this->size++;
        }
        else {
            int** newArray = new int* [this->capacity * 2];

            for (int i = 0; i < this->capacity * 2; i++)
                newArray[i] = nullptr;

            for (int i = 0; i < this->size; i++) {
                newArray[i] = new int;
                *newArray[i] = *this->list[i];
            }

            for (int i = 0; i < this->size; i++)
                delete this->list[i];
            delete[] this->list;

            this->capacity *= 2;
            this->list = newArray;

            this->list[this->size] = new int;
            *this->list[this->size] = newElement;
            this->size++;
            resizeMessage(this->size, this->capacity);
        }
        return *this;
    }

    void PrintList(string message) {
        cout << message;
        for (int i = 0; i < this->size; i++)
            cout << *this->list[i] << " ";
        cout << "\n";
    }

    const Array& Insert(const int & index, const int & newElement) {
        if (index < 0 || index >= this->capacity)
            throw Array_out_of_range();
        if (this->size < this->capacity) {
            this->list[this->size] = new int;
            *this->list[this->size] = 0;
            for (int i = this->size; i > index; i--)
                *this->list[i] = *this->list[i - 1];
            *this->list[index] = newElement;
            this->size++;
        }
        else {
            int** newArray = new int* [this->capacity * 2];
            for (int i = 0; i < this->capacity * 2; i++)
                newArray[i] = nullptr;

            for (int i = 0; i < this->capacity; i++) {
                if (this->list[i] != nullptr) {
                    newArray[i] = new int;
                    *newArray[i] = *this->list[i];
                }
            }

            for (int i = 0; i < this->capacity; i++)
                if (this->list[i] != nullptr)
                    delete this->list[i];
            delete[] this->list;
            this->list = newArray;
            this->capacity *= 2;
            this->list[this->size] = new int;
            *this->list[this->size] = newElement;
            this->size++;
            resizeMessage(this->size, this->capacity);
        }
        return *this;

    }

    const Array& Insert(const int& index, const Array& otherArray) {
        if (index < 0 || index >= size)
            throw Array_out_of_range();

        if (this->size + otherArray.size >= this->capacity) {
            throw Array_out_of_space();
        }

        if (this->size + otherArray.size < this->capacity) {
            for (int i = 0; i < otherArray.size; i++) {
                Insert(index + i, *otherArray.list[i]);
            }
        }
    }

    const Array& Delete(int index) {
        if (index < 0 || index >= this->size)
            throw Array_memory_coruption();
        for (int i = index; i < this->size - 1; i++)
            *this->list[i] = *this->list[i + 1];
        this->list[this->size - 1] = nullptr;
        this->size--;
        return *this;
    }

    bool operator=(const Array& otherArray) {
        for (int i = 0; i < this->size; i++)
            delete this->list[i];
        delete[] this->list;
        this->list = new int* [otherArray.capacity];
        this->capacity = otherArray.capacity;
        this->size = otherArray.size;
        for (int i = 0; i < this->capacity; i++) {
            if (otherArray.list[i] != nullptr) {
                this->list[i] = new int;
                *this->list[i] = *otherArray.list[i];
            }
            else
                this->list[i] = nullptr;
        }
        return true;
    }

    int GetSize() {
        return this->size;
    }
    int GetCapacity() {
        return this->capacity;
    }

    ArrayIterator GetBeginIterator() {
        return ArrayIterator(this->list, 0);
    }

    ArrayIterator GetEndIterator() {
        return ArrayIterator(this->list, this->size);
    }

};

int main()
{
    Array v(10);
    v += 4;
    v += 5;
    v += 6;
    v += 7;
    v += 8;
    v.PrintList("vectorul v este : ");
    ArrayIterator k = v.GetBeginIterator();
    for (k = v.GetBeginIterator(); k != v.GetEndIterator(); ++k) {
        cout << k.GetElement() << " ";
    }
    cout << "\n";
    return 0;
}
