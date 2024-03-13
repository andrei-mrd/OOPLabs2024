#include <iostream>
#include "Math.h"



int main() {
	std::cout << "suma a 2 numere intregi este : " << Math::Add(2, 3) << std::endl;
	std::cout << "suma a 3 numere intregi este : " << Math::Add(2, 3, 4) << std::endl;
	std::cout << "suma a 2 numere reale este : " << Math::Add((double)2, (double)3) << std::endl;;
	std::cout << "suma a 3 numere reale este : " << Math::Add((double)2, (double)3, (double)4) << std::endl;
	std::cout << "produsul a 2 numere intregi este : " << Math::Mul(2, 3) << std::endl;
	std::cout << "produsul a 3 numere intregi este : " << Math::Mul(2, 3, 4) << std::endl;
	std::cout << "produsul a 2 numere reale este : " << Math::Mul((double)2, (double)3) << std::endl;
	std::cout << "produsul a 3 numere reale este : " << Math::Mul((double)2, (double)3, (double)4) << std::endl;
	std::cout << "suma a 5 numere intregi este : " << Math::Add(5, 2, 3, 4, 5, 6) << std::endl;
	std::cout << "suma a 2 numere mari este : " << Math::Add("1123", "1157") << std::endl;

	return 0;
}
