#include <iostream>
#include "Demos.h"
using namespace std;

int main()
{
    Array<int> v(10);
    Array<int> m(10);
    v += 0;
    v += 1;
    v += 2;
    v += 3;
    v += 4;
    v += 5;
    v += 6;
    m += 10;
    m += 11;
    m += 9;
    v.Insert(2, m);
    cout << "Continutul vectorului este : ";
    for (int i = 0; i < 10; i++)
        cout << v[i] << " ";
    cout << "\n";
    v.Delete(4);
    cout << "Continutul vectorului dupe eliminarea lui 4 este : ";
    for (int i = 0; i < v.GetSize(); i++)
        cout << v[i] << " ";
    cout << "\n";
    cout<<"Capacitatea vectorului este : " << v.GetCapacity() << "; Iar marimea propriu zisa este : " << v.GetSize();
    v = m;
    cout << "\n";
    cout << "Continutul vectorului v este : ";
    for (int i = 0; i < v.GetSize(); i++)
        cout << v[i] << " ";
    v.Sort([](const int &a, const int &b) {if (a > b) return 1; return 0; });
    cout << "\n";
    cout << "Continutul vectorului v sortat este : ";
    for (int i = 0; i < v.GetSize(); i++)
        cout << v[i] << " ";
    cout << "\n";
    v += 12;
    v += 13;
    v += 14;
    v += 15;
    v += 16;
    cout << "Continutul vectorului v actualizat este : ";
    for (int i = 0; i < v.GetSize(); i++)
        cout << v[i] << " ";
    cout << "\n";
    if (v.BinarySearch(14) != -1) {
        cout << "Elementul 14 se afla pe pozitia : " << v.BinarySearch(14) << "\n";
    }
    else {
        cout << "Elementul nu se afla in vector" << "\n";
    }

    if (v.BinarySearch(14, [](const int& a, const int& b) {if (a == b) return 1; else if (a > b) return 0; else return -1; })) {
        cout << "Elementul 14 se afla pe pozitia : " << v.BinarySearch(14) << "\n";
    }
    else {
        cout << "Elementul nu se afla in vector" << "\n";
    }

    ArrayIterator<int> it = v.GetBeginIterator();
    while (it.GetElement() != nullptr) {
        cout << *it.GetElement() << " ";
        ++it;
    }
    return 0;
}
