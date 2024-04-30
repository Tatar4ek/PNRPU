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
    cout<< "Введите два числа: " << endl;
    cin >> pair;
    Rational rational;
    cout << "Введите два числа: " << endl;
    cin >> rational;

    Object *ptr = &pair;
    vect.add(ptr);
    ptr = &rational;
    vect.add(ptr);
    cout << vect;

    cout << "Содержание вектора: " << endl;
    cout << vect;


}