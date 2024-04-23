#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    Computer c;
    cout << "Объект c, созданный конструктором без параметров" << endl;
    c.show();

    string p;
    int r,d;

    cout << "Введите название процессора: "; cin >> p;
    cout << "Введите объем ОЗУ= "; cin >> r;
    cout << "Ведите объем ЖД= "; cin >> d;
    Computer c1(p,r,d);
    cout << "Объект, созданный конструктором с параметрами: " << endl;
    c1.show();

    Computer c2(c1);
    cout << "Объект, созданный конструктором копирования (c2(c1)): " << endl;
    c2.show();

    return 0;
}