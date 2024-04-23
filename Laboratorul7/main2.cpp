#include <iostream>
#include "Tree.h"
using namespace std;

float operator"" _Kelvin(unsigned long long int a) {
    return (float)a - 273.15;
}

float operator"" _Fahrenheit(unsigned long long int a) {
    return (float)a * 9.0 / 5.0 + 32.0;
}

int compare(int a, int b) {
    if (a == b)
        return 1;
    else if (a > b)
        return -1;
    return 0;
}

int main()
{
    float a = 320_Kelvin;
    float b = 120_Fahrenheit;
    //cout << a << " " << b;

    Tree<int> c;
    nod<int>* root = nullptr;
    c.add_node(root, 5);
    c.add_node(root, 10);
    c.add_node(root, 12);
    c.add_node(root, 5);
    c.add_node(root, 18);
    c.add_node(root, 8);
    //c.print(root);
    //std::cout << "\n";
    c.insert(root, 2, 7);
    //std::cout << "\n";
     c.print(root);
    //std::cout << "\n";
    //c.sort(root, compare);
    //c.print(root);
    std::cout << "\n";
    //std::cout << c.count(root);
    // std::cout<<c.find(root, 10, compare)->info;
}