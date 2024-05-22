#pragma once
#include <exception>

class out_of_range : public std::exception {
	virtual const char* what() const throw() {
		return "Index invalid";
	}
};

class exception1 : public std::exception {
	virtual const char* what() const throw() {
		return "Exceptie";
	}
};

class Compare
{
public:
	virtual int CompareElements(void* e1, void* e2) = 0;
};

template<class T>
class ArrayIterator {
private:
	int Current;
	T** List;
public:
	ArrayIterator(T** list, int current) : List(list), Current(current) {}

	ArrayIterator& operator++() {
		++this->Current;
		return *this;
	}

	ArrayIterator& operator--() {
		--this->Current;
		return *this;
	}

	bool operator=(ArrayIterator<T>& other) {
		if (this != &other) {
			this->List = other.List;
			this->Current = other.Current;
		}
	}

	bool operator!=(ArrayIterator<T>& other) {
		return this->Current != other.Current;
	}

	T* GetElement() {
		return this->List[this->Current];
	}
};

template <class T>
class Array {
private:
	T** List; //Lista de tip pointer la pointer
	int Size;
	int Capacity;
public:
	//constructor default
	Array() {
		this->List = nullptr;
		this->Size = 0;
		this->Capacity = 0;
	}

	//destructor
	~Array() {
		for (int i = 0; i < this->Capacity; i++)
			delete[] this->List[i];
		delete[] this->List;
		this->Size = 0;
		this->Capacity = 0;
	}

	//constructor cu 'capacity' elemente
	Array(int capacity) {
		this->Size = 0;
		this->Capacity = capacity;
		this->List = new T * [capacity];
	}

	//constructor de copiere
	Array(const Array<T>& otherArray) {
		for (int i = 0; i < this->Capacity; i++) {
			delete[] this->List[i];
		}
		delete[] this->List;
		this->List = new T * [otherArray.Capacity];
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		for (int i = 0; i < this->Capacity; i++)
			this->List[i] = otherArray.List[i];
	}

	//arunca o exceptie daca index e out of range
	T& operator[](int index) {
		if (index >= this->Capacity) {
			throw std::out_of_range("Index invalid");
		}
		else {
			return this->List[index][0];
		}
	}

	// adauga un element de tipul T la sfarsitul listei si returneaza this
	const Array<T>& operator +=(const T& newElement) {
		if (this->Size < this->Capacity) {
			this->List[this->Size] = new T;
			this->List[this->Size][0] = newElement;
			this->Size++;
		}
		else {
			T** newArray = new T * [this->Capacity + 1];
			for (int i = 0; i < this->Capacity; i++) {
				newArray[i] = new T;
				newArray[i][0] = this->List[i][0];
			}
			for (int i = 0; i < this->Capacity; i++) {
				delete[] this->List[i];
			}
			delete[] this->List;
			this->List = newArray;
			this->Capacity ++;
			this->List[this->Size] = new T;
			this->List[this->Size][0] = newElement;
			this->Size++;
		}
		return *this;
	}

	// adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const T& newElement) {
		if (index >= this->Capacity || index < 0) {
			throw out_of_range();
		}
		else {
			if (this->Size + 1 <= this->Capacity) {
				this->List[this->Size] = new T;
				for (int i = this->Size; i > index; i--) {
					this->List[i][0] = this->List[i - 1][0];
				}
				this->List[index][0] = newElement;
				this->Size++;
			}
			else {
				T** newArray = new T * [this->Capacity + 1];
				for (int i = 0; i < this->Capacity; i++) {
					newArray[i] = new T;
					newArray[i][0] = this->List[i][0];
				}
				for (int i = 0; i < this->Capacity; i++) {
					delete[] this->List[i];
				}
				delete[] this->List;
				this->List = newArray;
				this->Capacity ++;
				this->List[this->Size] = new T;
				for (int i = this->Size; i > index; i--) {
					this->List[i][0] = this->List[i - 1][0];
				}
				this->List[index][0] = newElement;
				this->Size++;;
			}
		}
		return *this;
	}

	// adauga o lista pe pozitia index, retureaza this.Daca index e invalid arunca o exceptie
	const Array<T>& Insert(int index, const Array<T>& otherArray) {
		if (index >= this->Capacity || index < 0) {
			throw exception1();
		}
		else {
			if (this->Size + otherArray.Size <= this->Capacity) {
				for (int i = this->Size; i < this->Size + otherArray.Size; i++) {
					this->List[i] = new T;
				}
				for (int i = index; i < this->Size; i++) {
					if (i + otherArray.Size < this->Size) {
						this->List[i + otherArray.Size * 2][0] = this->List[i + otherArray.Size][0];
						this->List[i + otherArray.Size][0] = this->List[i][0];
					}
					else if (i + otherArray.Size == this->Size) {
						this->List[i + otherArray.Size][0] = this->List[i][0];
					}
				}
				int cnt = 0;
				for (int i = index; i < index + otherArray.Size; i++) {
					this->List[i][0] = otherArray.List[cnt][0];
					cnt++;
				}
				this->Size += otherArray.Size;
			}
			else {
				T** newArray = new T * [this->Capacity + otherArray.Capacity];
				for (int i = 0; i < this->Capacity; i++) {
					newArray[i] = new T;
					newArray[i][0] = this->List[i][0];
				}
				for (int i = 0; i < this->Capacity; i++) {
					delete[] this->List[i];
				}
				delete[] this->List;
				this->List = newArray;
				this->Capacity+= otherArray.Capacity;
				for (int i = this->Size; i < this->Size + otherArray.Size; i++) {
					this->List[i] = new T;
				}
				for (int i = index; i < this->Size; i++) {
					if (i + otherArray.Size < this->Size) {
						this->List[i + otherArray.Size * 2][0] = this->List[i + otherArray.Size][0];
						this->List[i + otherArray.Size][0] = this->List[i][0];
					}
					else if (i + otherArray.Size == this->Size) {
						this->List[i + otherArray.Size][0] = this->List[i][0];
					}
				}
				int cnt = 0;
				for (int i = index; i < index + otherArray.Size; i++) {
					this->List[i][0] = otherArray.List[cnt][0];
					cnt++;
				}
				this->Size += otherArray.Size;
			}
		}
		return *this;
	}
	
	// sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie
	const Array<T>& Delete(int index) {
		if (index < 0 || index >= this->Capacity)
			throw std::exception("DELETE : Index invalid");
		for (int i = index; i < this->Size - 1; i++)
			this->List[i][0] = this->List[i + 1][0];
		this->List[this->Size - 1] = nullptr;
		this->Size--;
		return *this;
	}

	bool operator=(const Array<T>& otherArray) {
		for (int i = 0; i < this->Capacity; i++)
			delete this->List[i];
		delete[] this->List;
		this->List = new T * [otherArray.Capacity];
		for (int i = 0; i < otherArray.Size; i++) {
			this->List[i] = new T;
			this->List[i][0] = otherArray.List[i][0];
		}
		this->Capacity = otherArray.Capacity;
		this->Size = otherArray.Size;
		return true;
	}

	// sorteaza folosind comparatia intre elementele din T
	void Sort() {
		bool sort;
		do {
			sort = true;
			for (int i = 0; i < this->Size - 1; i++) {
				if (this->List[i][0] > this->List[i + 1][0]) {
					T aux = this->List[i][0];
					this->List[i][0] = this->List[i + 1][0];
					this->List[i + 1][0] = aux;
					sort = false;
				}
			}
		} while (!sort);
	}

	// sorteaza folosind o functie de comparatie
	void Sort(int(*compare)(const T&, const T&)) {
		bool sort;
		do {
			sort = true;
			for (int i = 0; i < this->Size - 1; i++) {
				if (compare(this->List[i][0], this->List[i + 1][0])) {
					T aux = this->List[i][0];
					this->List[i][0] = this->List[i + 1][0];
					this->List[i + 1][0] = aux;
					sort = false;
				}
			}
		} while (!sort);
	}

	// sorteaza folosind un obiect de comparatie
	void Sort(Compare* compare) {
		bool sort;
		do {
			sort = true;
			for (int i = 0; i < this->Size - 1; i++) {
				if (compare->CompareElements(this->List[i][0], this->List[i + 1][0]) == 0) {
					T aux = this->List[i][0];
					this->List[i][0] = this->List[i + 1][0];
					this->List[i + 1][0] = aux;
					sort = false;
				}
			}
		} while (!sort);
	}

	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
	// cauta un element folosind binary search in Array
	int BinarySearch(const T& elem) {
		int st = 0, dr = this->Size - 1, mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (elem == this->List[mij][0]) {
				return mij;
			}
			else if (elem > this->List[mij][0]) {
				st = mij + 1;
			}
			else {
				dr = mij - 1;
			}
		}
		return -1;
	}

	// cauta un element folosind binary search si o functie de comparatie
	int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
		int st = 0, dr = this->Size - 1, mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (compare(elem, this->List[mij][0]) == 1) {
				return mij;
			}
			else if (compare(elem, this->List[mij][0]) == 0) {
				st = mij + 1;
			}
			else {
				dr = mij - 1;
			}
		}
		return -1;
	}

	//  cauta un element folosind binary search si un comparator
	int BinarySearch(const T& elem, Compare* comparator) {
		int st = 0, dr = this->Size - 1, mij;
		while (st <= dr)
		{
			mij = (st + dr) / 2;
			if (comparator->CompareElements(elem, this->List[mij][0]) == 1) {
				return mij;
			}
			else if (comparator->CompareElements(elem, this->List[mij][0]) == 0) {
				st = mij + 1;
			}
			else {
				dr = mij - 1;
			}
		}
		return -1;
	}

	// cauta un element in Array
	int Find(const T& elem) {
		for (int i = 0; i < this->Size; i++) {
			if (this->List[i][0] == elem) {
				return i;
			}
		}
		return -1;
	}

	//  cauta un element folosind o functie de comparatie
	int Find(const T& elem, int(*compare)(const T&, const T&)) {
		for (int i = 0; i < this->Size; i++) {
			if (compare(this->List[i][0], elem)) {
				return i;
			}
		}
		return -1;
	}

	//  cauta un element folosind un comparator
	int Find(const T& elem, Compare* comparator) {
		for (int i = 0; i < this->Size; i++) {
			if (comparator->CompareElements(this->List[i][0], elem) == 1) {
				return i;
			}
		}
		return -1;
	}

	int GetSize() {
		return this->Size;
	}
	int GetCapacity() {
		return this->Capacity;
	}

	ArrayIterator<T> GetBeginIterator() {
		return ArrayIterator<T>(List, 0);
	}

	ArrayIterator<T> GetEndIterator() {
		return ArrayIterator<T>(List, Size);
	}

};
