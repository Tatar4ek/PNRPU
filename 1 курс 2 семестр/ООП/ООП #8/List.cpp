#include "List.h"
#include "Event.h"
#include "Person.h"
#include "Student.h"

List::~List(void)
{
	if (beg != 0)delete[] beg;
	beg = 0;
}

List::List(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}

List::List()
{
	beg = new Object * [0];
	cur = 0;
	size = 0;
}

void List::Add()
{
	Object* p;

	cout << "1.Person" << endl;
	cout << "2.Emloyee" << endl;
	int y;
	cin >> y;
	if (y == 1)
	{
		Person* a = new (Person);
		a->Input();
		p = a;

		if (cur < size)
		{
			beg[cur] = p;
			cur++;
		}
	}
	else
		if (y == 2)
		{
			Student* b = new Student;
			b->Input();
			p = b;

			if (cur < size)
			{
				beg[cur] = p;
				cur++;
			}
		}
		else 
			return;
}

void List::Show()
{
	if (cur == 0) 
		cout << "Empty" << endl;

	Object** p = beg;

	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

void List::Name()
{
	if (cur == 0) 
		return;

	string name = "";
	int a;
	cout << "\nNumber: " << endl;
	cin >> a;
	Object** p = beg;
	p = p + a - 1;
	name = (*p)->GetName();

	cout << "Name: " << name << endl;
}

int List::operator ()()
{
	return cur;
}

void List::Del()
{
	if (cur == 0)
		return;
	cur--;
}

void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}