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