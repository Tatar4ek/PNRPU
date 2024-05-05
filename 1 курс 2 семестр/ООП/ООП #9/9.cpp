#include "set.h"
#include <iostream>
using namespace std;

int main()
{
    try
    {
    Set s1;
    cin >> s1;
    Set s2;
    cin >> s2;
    }

    catch (Error& e)
	{
		e.what();
	}

    return 0;
}
