#include <iostream>
#include "Pair.h"
#include "Rational.h"
#include "Vector.h"
#include "Object.h"
using namespace std;

int main()
{
    Vector vect(5);
    Pair pair;
    cout<< "������� ��� �����: " << endl;
    cin >> pair;
    Rational rational;
    cout << "������� ��� �����: " << endl;
    cin >> rational;

    Object *ptr = &pair;
    vect.add(ptr);
    ptr = &rational;
    vect.add(ptr);
    cout << vect;

    cout << "���������� �������: " << endl;
    cout << vect;


}