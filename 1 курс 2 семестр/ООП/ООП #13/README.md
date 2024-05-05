Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## Обработка исключительных ситуаций

Лабораторная работа №10 - Классы.

Создать класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
- сложение денежных сумм,
- вычитание денежных сумм,
Задание:
- Удалить все записи равные заданному значению.
- Увеличить все записи с заданным значением на 1 рубль 50 копеек.
- Добавить К записей после элемента с заданным номером.
## Код программы

>money.h
```C++
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Money
{
public:
	int rub;
	int kop;

	Money() { rub = 0; kop = 0; };
	Money(int m, int s) { rub = m; kop = s; }
	Money(int s) { rub = 0; kop = s; }
	Money(const Money& t) { rub = t.rub; kop = t.kop; }
	~Money() {};

	void clear() { kop = 0; };
	int get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(int m) { rub = m; }
	void set_kop(int s) { kop = s; }

	Money& operator=(const Money&);
	Money& operator++();
	Money operator++(int);
	Money operator+(const Money&);
	Money operator-(const Money&);
	Money operator/(const Money& t)
	{
		int temp1 = rub * 100 + kop;
		int temp2 = t.rub * 100 + t.kop;
		Money p;
		p.rub = (temp1 / temp2) / 100;
		p.kop = (temp1 / temp2) % 100;
		return p;
	}

	bool operator <(const Money& t)
	{
		if (rub < t.rub)
			return true;
		if (rub == t.rub && kop < t.kop)
			return true;

		return false;
	}
	bool operator >(const Money& t)
	{
		if (rub > t.rub)
			return true;
		if (rub == t.rub && kop > t.kop)
			return true;

		return false;
	}

	bool operator ==(const Money& t)
	{
		if (rub != t.rub)return false;
		if (kop == t.kop) return true;
		return false;
	}

	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
	friend fstream& operator>>(fstream& fin, Money& p);
	friend fstream& operator<<(fstream& fout, const Money& p);
};```

>money.cpp
```C++
#include "Money.h"
#include <iostream>
#include <windows.h>

using namespace std;

Money& Money::operator=(const Money& t)
{
	if (&t == this)
		return *this;

	rub = t.rub;
	kop = t.kop;

	return *this;
}

Money& Money::operator++()
{
	int temp = rub * 100 + kop;
	temp++;

	rub = temp / 100;
	kop = temp % 100;

	return *this;
}

Money Money::operator ++(int)
{
	int temp = rub * 100 + kop;
	temp++;
	Money t(rub, kop);

	rub = temp / 100;
	kop = temp % 100;

	return t;
}

Money Money::operator+(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;

	Money p;

	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;

	return p;
}

Money Money::operator-(const Money& t)
{
	int temp1 = rub * 100 - kop;
	int temp2 = t.rub * 100 - t.kop;

	Money p;

	p.rub = (temp1 - temp2) / 100;
	p.kop = (temp1 - temp2) % 100;

	return p;
}

istream& operator>>(istream& in, Money& t)
{
	cout << "Enter Rubles: "; in >> t.rub;
	cout << "Enter Kop: "; in >> t.kop;

	return in;
}

ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}

fstream& operator>>(fstream& fin, Money& p)
{
	fin >> p.rub;
	fin >> p.kop;

	return fin;
}
fstream& operator <<(fstream& fout, const Money& p)
{
	fout << to_string(p.rub) << "\n" << p.kop << "\n";

	return fout;
}
```

>13_1.cpp
```C++
#include "Money.h" 
#include "vector"
#include <iostream> 
#include <conio.h>
#include <algorithm>
#include <list>
#include <iterator>

using namespace std;

typedef list<Money> TList;

TList make_list(int n)
{
	Money a;
	TList v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void print_list(TList v)
{
	for (auto it = v.begin(); it != v.end(); ++it)
		std::cout << *it << " ";

	std::cout << std::endl;
}

Money s;
Money p;

Money minmax(TList v)
{
	TList::iterator x;

	x = min_element(v.begin(), v.end());
	std::cout << "min =" << *(x) << endl;
	Money g = *(x);

	TList::iterator y;

	y = max_element(v.begin(), v.end());
	std::cout << "max = " << *(y) << endl;

	Money h = *(y);
	Money p = h - g;
	std::cout << "min - max = " << p << endl;
	return p;
}

struct Greater_s
{
	bool operator()(Money t)
	{
		if (t > s) return true; else return false;
	}
};

struct Comp_less
{
public:
	bool operator()(Money t1, Money t2)
	{

		if (t1 > t2)return true;
		else return false;
	}
};

struct Equal_s
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

void del(Money& t)
{
	t = t + p;
}

int main()
{
	int n;
	cout << "Number: ";
	cin >> n;

	TList v;
	v = make_list(n);
	print_list(v);

	TList::iterator i;
	TList::iterator pos;

	int num;
	cout << "Add object " << endl;
	cin >> s;

	cout << "Pos for add: " << endl; 
	cin >> num;

	i = find_if(v.begin(), v.end(), Equal_s());

	pos = next(v.begin(), num);
	if (i != v.end())
	{
		cout << "Object: " << *(i) << endl << "Added for " << num << "pos" << endl;

		v.insert(pos, s);
		print_list(v);
	}
	else
		cout << "Not such element!" << endl;

	cout << "Delete object " << endl;
	cin >> s;

	i = find_if(v.begin(), v.end(), Equal_s());
	if (i != v.end())
	{
		cout << "Number:" << *(i) << endl << "Deleting" << endl;
		s = *i;

		i = remove_if(v.begin(), v.end(), Equal_s());

		v.erase(i, v.end());
		print_list(v);
	}
	else
		cout << "Not such element!" << endl;

	cout << "Raznica min and max elementov" << endl;
	p = minmax(v);

	for_each(v.begin(), v.end(), del);
	print_list(v);
}

```

>13_2.cpp
```C++
#include "Money.h" 
#include "deque" 
#include "queue" 
#include <iostream> 
#include <conio.h>
#include <algorithm> 

using namespace std;

typedef queue<Money> que;
typedef deque<Money> deq;

que make_queue(int n)
{
	que s;
	Money t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s.push(t);
	}
	return s;
}

deq copy_queue_to_deque(que s)
{
	deq v;
	while (!s.empty())
	{
		v.push_back(s.front());
		s.pop();
	}
	return v;
}

que copy_deque_to_queue(deq v)
{
	que s;
	for (int i = 0; i < v.size(); i++)
		s.push(v[i]);

	return s;
}

void print_queue(que s)
{
	std::cout << endl;
	deq v = copy_queue_to_deque(s);

	while (!s.empty())
	{
		std::cout << s.front() << endl;
		s.pop();
	}

	s = copy_deque_to_queue(v);
	std::cout << endl;
}

Money s;

struct Greater_s
{
	bool operator()(Money t)
	{
		if (t > s) 
			return true;
		else
			return false;
	}
};

struct Comp_less
{
public:
	bool operator()(Money t1, Money t2)
	{

		if (t1 > t2)
			return true;
		else
			return false;
	}
};

Money minmax(que s)
{
	deq v = copy_queue_to_deque(s);
	deq::iterator x;

	x = min_element(v.begin(), v.end());
	std::cout << "min = " << *(x) << endl;
	Money g = *(x);

	deq::iterator y;
	y = max_element(v.begin(), v.end());
	std::cout << "max = " << *(y) << endl;

	Money h = *(y);
	Money p = h + g;

	std::cout << "min + max = " << p << endl;
	return p;
}

struct Equal_s
{
	bool operator()(Money t)
	{
		return t == s;
	}
};

void del(Money& t)
{
	t = t + s;
}

int main()
{
	int n;
	cout << "Number: ";
	cin >> n;

	que v;
	v = make_queue(n);
	print_queue(v);

	deq vv;
	deq::iterator i;

	vv = copy_queue_to_deque(v);
	i = min_element(vv.begin(), vv.end());

	cout << "min = " << *(i) << endl;

	Money m = *(i);

	vv.push_back(m);
	v = copy_deque_to_queue(vv);
	print_queue(v);
	cin >> s;

	i = find_if(vv.begin(), vv.end(), Equal_s());

	if (i != vv.end())
	{
		cout << "Number:" << *(i) << endl << "Deleting" << endl;
		s = *i;

		i = remove_if(vv.begin(), vv.end(), Equal_s());

		vv.erase(i, vv.end());
		v = copy_deque_to_queue(vv);
		print_queue(v);
	}
	else
		cout << "Not such element!" << endl;

	cout << "Adding" << endl;
	s = minmax(v);

	for_each(vv.begin(), vv.end(), del);
	v = copy_deque_to_queue(vv);
	print_queue(v);
}
```

>13_3.cpp
```C++
#include <iostream>  
#include "Money.h"
#include <algorithm> 
#include <set>

using  namespace  std;

typedef  multiset<int> mst;
typedef multiset<int> ::iterator it;

mst make_map(int n)
{
    mst m;
    int a;
    for (int i = 0; i < n; i++)
    {
        cout << "?";
        cin >> a;

        m.insert(a);
    }

    return m;
}

void print_map(mst v)
{
    multiset <int> ::iterator it = v.begin();

    cout << "Sorted: " << endl;
    for (int i = 1; it != v.end(); i++, it++)
        cout << *it << " ";
}

int srednee(mst v)
{
    int s = 0;
    multiset <int>::iterator it = v.begin();

    for (int i = 1; it != v.end(); i++, it++)
        s += *it;

    return s / v.size();
}

Money s;

int main()
{
    int n;
    Money t;
    cout << "Number: ";
    cin >> n;
    mst v = make_map(n);
    print_map(v);

    mst::iterator i;

    i = max_element(v.begin(), v.end());
    s = srednee(v);

    cout << "Middle = " << s << endl;
    return 0;
}
```
# UML

<image src="13.png">

# Пример работы

<image src="13_1.png">
13_1.cpp

<image src="13_2.png">
13_2.cpp

<image src="13_3.png">
13_3.cpp
