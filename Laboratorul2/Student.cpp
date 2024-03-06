#include "Student.h"
#include <iostream>
#include <cstring>


void Student::SetName(const char * name) {
	strcpy_s(this->name, name);
}

char* Student::GetName() {
	return this->name;
}

void Student::Set_M_Grade(float grade) {
	this->m_grade = grade;
}

float Student::Get_M_Grade() {
	return this->m_grade;
}

void Student::Set_E_Grade(float grade) {
	this->e_grade = grade;
}

float Student::Get_E_Grade() {
	return this->e_grade;
}

void Student::Set_H_Grade(float grade) {
	this->h_grade = grade;
}

float Student::Get_H_Grade() {
	return this->h_grade;
}

float Student::Get_A_Grade() {
	float sum = this->m_grade + this->e_grade + this->h_grade;
	sum /= 3;
	return sum;
}
