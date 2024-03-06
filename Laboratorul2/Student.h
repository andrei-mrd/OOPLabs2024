#pragma once
class Student
{
	char name[100];
	float m_grade, e_grade, h_grade;

public:
	void SetName(const char * name);
	char* GetName();

	void Set_M_Grade(float grade);
	float Get_M_Grade();

	void Set_E_Grade(float grade);
	float Get_E_Grade();

	void Set_H_Grade(float grade);
	float Get_H_Grade();

	float Get_A_Grade();
};

