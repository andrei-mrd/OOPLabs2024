#include <iostream>
#include <tuple>
#include "Map.h"
using namespace std;

tuple<int, int, int> CreatePerson() {
    return { 12, 15, 17 };
}


int main()
{

    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    for (auto [key, value, index] : m) {
        cout <<"Index="<<index << ", Key=" << key << ", Value=" << value << "\n";
    }
    m[20] = "result";
    for (auto [key, value, index] : m) {
        cout << "Index=" << index << ", Key=" << key << ", Value=" << value << "\n";
    }

    cout << m.Get(20, "result") << "\n";
    cout << m.Count() << "\n";

    m.Delete(30);

    cout << "Map m: \n";

    for (auto [key, value, index] : m) {
        cout << "Index=" << index << ", Key=" << key << ", Value=" << value << "\n";
    }

    Map<int, const char*> n;
    n[10] = "C++";
    n[20] = "result";
    n[30] = "Poo";

    cout << "Map n: \n";

    for (auto [key, value, index] : n) {
        cout << "Index=" << index << ", Key=" << key << ", Value=" << value << "\n";
    }

    cout << n.Includes(m);
    return 0;
}