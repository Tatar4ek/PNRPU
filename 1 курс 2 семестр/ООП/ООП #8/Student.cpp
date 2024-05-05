#include "Student.h"

Student::Student(void) :Person()
{
	wage = 0;
}

Student::~Student(void){}

Student::Student(string F, int S, int G, string R) :Person(F, S)
{
	wage = G;
}

Student::Student(const Student& L)
{
	name = L.name;
	age = L.age;
	wage = L.wage;
}

void Student::Set_Point(int G)
{
	wage = G;
}

Student& Student::operator=(const Student& L)
{
	if (&L == this)
		return *this;

	name = L.name;
	age = L.age;
	wage = L.wage;

	return *this;
}

void Student::Input()
{
	cout << "\nName:"; cin >> name;
	cout << "\nAge:"; cin >> age;
	cout << "\nRate:"; cin >> wage;
}

void Student::Show()
{
	cout << "\nName : " << name;
	cout << "\nAge : " << age;
	cout << "\nRate: " << wage;
	cout << "\n";
}