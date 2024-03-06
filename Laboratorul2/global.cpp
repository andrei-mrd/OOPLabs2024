#include "global.h"
#include <iostream>
#include <cstring>

int compareBy_Name(Student* c1, Student* c2) {
	if (strcmp(c1->GetName(), c2->GetName()) > 0) {
		return 1;
	}
	else if (strcmp(c1->GetName(), c2->GetName()) == 0) {
		return 0;
	}
	else return -1;
}

int compareBy_M_Grade(Student* c1, Student* c2) {
	if (c1->Get_M_Grade() > c2->Get_M_Grade()) {
		return 1;
	}
	else if (c1->Get_M_Grade() == c2->Get_M_Grade()) {
		return 0;
	}
	else return -1;
}

int compareBy_E_Grade(Student* c1, Student* c2) {
	if (c1->Get_E_Grade() > c2->Get_E_Grade()) {
		return 1;
	}
	else if (c1->Get_E_Grade() == c2->Get_E_Grade()) {
		return 0;
	}
	else return -1;
}

int compareBy_H_Grade(Student* c1, Student* c2) {
	if (c1->Get_H_Grade() > c2->Get_H_Grade()) {
		return 1;
	}
	else if (c1->Get_H_Grade() == c2->Get_H_Grade()) {
		return 0;
	}
	else return -1;
}

int compareBy_A_Grade(Student* c1, Student* c2) {
	if (c1->Get_A_Grade() > c2->Get_A_Grade()) {
		return 1;
	}
	else if (c1->Get_A_Grade() == c2->Get_A_Grade()) {
		return 0;
	}
	else return -1;
}
