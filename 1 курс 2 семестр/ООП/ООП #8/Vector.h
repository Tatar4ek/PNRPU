#pragma once
#include "Object.h"
#include <string>
#include <iostream>

using namespace std;

class List
{
public:
	List(int);
	List();
	~List(void);
	void Add();
	void Del();
	void Show();
	void Name();
	int operator()();
	virtual void HandleEvent(const TEvent& e);

protected:
	Object** beg;
	int size;
	int cur;
};