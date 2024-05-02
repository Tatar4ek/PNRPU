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

    cout << "Деньги в moneySet: ";
    moneySet.print();

    Money money4(50, 25);
    if (moneySet.contains(money4)) {
        cout << "Деньги " << money4 << " есть в множестве." << endl;
    } else {
        cout << "Деньги " << money4 << " отсутствуют в множестве." << endl;
    }

    Set<Money> moneySet2;
    Money money5(75, 30);
    moneySet2.add(money4);
    moneySet2.add(money5);

    Set<Money> intersection = moneySet * moneySet2;
    cout << "Результат пересечения двух множеств: ";
    intersection.print();

    cout << "Размер moneySet: " << int(moneySet) << endl;

    return 0;
}
