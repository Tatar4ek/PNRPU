#include <iostream>
#include "Pair.h"
#include "Rational.h"
using namespace std;

int main()
{
    Pair a(10,20);
    Pair b(30,20);
    Rational a1(28,37);
    Rational b1(18,29);
    bool c;
    c = a == b;
    cout << c << endl;
    a *= b;
    a -= b;
    a1 -= b1;
    a1 += b1;
    a1 *= b1;
}