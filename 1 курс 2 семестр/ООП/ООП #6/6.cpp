#include <iostream>
#include "set.h"
using namespace std;

int main() {
    system("chcp 1251");
    Set set1;
    cin >> set1;
    Iterator it = set1.get_last();
    cout << "Последний элемент: (Итератор находится на последнем элементе) " << *(it) << endl;
    --it;
    cout << "Предпоследний элемент: (Итератор перемещен назад на 1 элемент от последнего элемента) " << *(it) << endl;
    return 0;
}
