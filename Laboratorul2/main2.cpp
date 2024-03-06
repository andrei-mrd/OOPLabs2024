#include <iostream>
#include "Student.h"
#include "global.h"
using namespace std;

int main()
{
	Student s1, s2;

	s1.SetName("Andrei");
	s2.SetName("Daniel");

	s1.Set_M_Grade(9.5);
	s2.Set_M_Grade(8.5);

	s1.Set_H_Grade(9.2);
	s2.Set_H_Grade(9.8);

	s1.Set_E_Grade(7.2);
	s2.Set_E_Grade(8.2);

	if (compareBy_Name(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " este mai inaintat alfabetic" << "\n"; 
	}
	else if (compareBy_Name(&s1, &s2) == 0) { 
		std::cout << "Sunt la fel alafabetic" << "\n"; 
	}
	else std::cout << s2.GetName() << " este mai inaintat alfabetic" << "\n";

	if (compareBy_M_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are nota mai mare la mate" << "\n";
	}
	else if (compareBy_M_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi nota la mate" << "\n";
	}
	else std::cout << s2.GetName() << " are nota mai mare la mate" << "\n";

	if (compareBy_H_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are nota mai mare la istorie" << "\n";
	}
	else if (compareBy_H_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi nota la istorie" << "\n";
	}
	else std::cout << s2.GetName() << " are nota mai mare la istorie" << "\n";

	if (compareBy_E_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are nota mai mare la engleza" << "\n";
	}
	else if (compareBy_E_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi nota la engleza" << "\n";
	}
	else std::cout << s2.GetName() << " are nota mai mare la engleza" << "\n";

	if (compareBy_A_Grade(&s1, &s2) == 1) {
		std::cout << s1.GetName() << " are media mai mare" << "\n";
	}
	else if (compareBy_A_Grade(&s1, &s2) == 0) {
		std::cout << "Au aceeasi medie" << "\n";
	}
	else std::cout << s2.GetName() << " are media mai mare" << "\n";

	return 0;
}