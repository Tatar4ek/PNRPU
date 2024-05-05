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

	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
	friend fstream& operator>>(fstream& fin, Money& p);
	friend fstream& operator <<(fstream& fout, const Money& p);
};