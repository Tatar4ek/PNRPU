#include "Person.h"
#include "Event.h"

Person::Person(void)
{
	name = "";
	age = 0;
}

Person::~Person(void){}

Person::Person(string F, int S)
{
	name = F;
	age = S;
}

Person::Person(const Person& person)
{
	name = person.name;
	age = person.age;
}

void Person::Set_Name(string F)
{
	name = F;
}

void Person::Set_Age(int S)
{
	age = S;
}

Person& Person::operator=(const Person& c)
{
	if (&c == this)
		return *this;

	name = c.name;
	age = c.age;

	return *this;
}

void Person::Input()
{
	cout << "\nName:"; cin >> name;
	cout << "\nAge:"; cin >> age;
}


void Person::Show()
{
	cout << "\nName : " << name;
	cout << "\nAge : " << age;

	cout << "\n";
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:cout << "Name = " << GetName() << endl;
			break;
		}
	}
}