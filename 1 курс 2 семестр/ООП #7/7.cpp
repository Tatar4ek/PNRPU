#include <iostream>
#include "set.h"
#include "Money.h"
using namespace std;

int main() {
    Set<Money> moneySet;

    Money money1(100, 50);
    Money money2(50, 25);
    Money money3(75, 30);

    moneySet.add(money1);
    moneySet.add(money2);
    moneySet.add(money3);

    cout << "������ � moneySet: ";
    moneySet.print();

    Money money4(50, 25);
    if (moneySet.contains(money4)) {
        cout << "������ " << money4 << " ���� � ���������." << endl;
    } else {
        cout << "������ " << money4 << " ����������� � ���������." << endl;
    }

    Set<Money> moneySet2;
    Money money5(75, 30);
    moneySet2.add(money4);
    moneySet2.add(money5);

    Set<Money> intersection = moneySet * moneySet2;
    cout << "��������� ����������� ���� ��������: ";
    intersection.print();

    cout << "������ moneySet: " << int(moneySet) << endl;

    return 0;
}
