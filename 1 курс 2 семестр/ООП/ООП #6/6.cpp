#include <iostream>
#include "set.h"
using namespace std;

int main() {
    system("chcp 1251");
    Set set1;
    cin >> set1;
    Iterator it = set1.get_last();
    cout << "��������� �������: (�������� ��������� �� ��������� ��������) " << *(it) << endl;
    --it;
    cout << "������������� �������: (�������� ��������� ����� �� 1 ������� �� ���������� ��������) " << *(it) << endl;
    return 0;
}
