#include "Computer.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    setlocale(LC_ALL, "RUS");
    Computer c;
    cout << "������ c, ��������� ������������� ��� ����������" << endl;
    c.show();

    string p;
    int r,d;

    cout << "������� �������� ����������: "; cin >> p;
    cout << "������� ����� ���= "; cin >> r;
    cout << "������ ����� ��= "; cin >> d;
    Computer c1(p,r,d);
    cout << "������, ��������� ������������� � �����������: " << endl;
    c1.show();

    Computer c2(c1);
    cout << "������, ��������� ������������� ����������� (c2(c1)): " << endl;
    c2.show();

    return 0;
}