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