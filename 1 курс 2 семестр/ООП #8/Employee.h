#pragma once
#include <string>
#include "Person.h"

class Student :
	public Person
{
public:
	Student(void);
	~Student(void);
	Student(string, int, int, string);
	Student(const Student&);

	void Set_Point(int);
	void Input();
	void Show();

	Student& operator=(const Student&);

protected:
	int wage;
};