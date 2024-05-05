#include <iostream>
#include "interpolation_search.h"
#include "lomuto_sort.h"
#include "linear_search.h"
#include "binary_search.h"
using namespace std;


void print_array(int arr[], int size) {
    if (size != 0) {
        cout << arr[0];
    }
    for (int i = 1; i < size; i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}


int main() {
    setlocale(LC_ALL, "RUS");
    int size, key, tmp;
    cout << "������� ������ ������� ����� �����." << endl;
    cin >> size;
    int array_of_numbers[size];
    for (int i = 0; i < size; i++) {
        cout << "������� ������� - ����� �����: ";
        cin >> tmp;
        array_of_numbers[i] = tmp;
        cout << endl;
    }

    cout << "������� ����: ";
    cin >> key;
    cout << endl;

    cout << "�������� ����� ������:" << endl;
    cout << "1)��������\n2)����������������\n3)��������" << endl;
    int search_number;
    cin >> search_number;

    switch (search_number) {
    case 1: {
        cout << "��������� ������:" << endl;
        print_array(array_of_numbers, size);
        cout << "������ ������ �������� ������� ������� �����: " << linear_search(array_of_numbers, size, key) << endl;

        break;
    }
    case 2: {
        quick_lomuto(array_of_numbers, 0, size - 1);
        cout << "������ ����� ����������:" << endl;
        print_array(array_of_numbers, size);
        cout << "������ ������ �������� ������� ������� �����: " << interpolation_search(array_of_numbers, 0, size - 1, key) << endl;

        break;
    }
    case 3: {
        quick_lomuto(array_of_numbers, 0, size - 1);
        cout << "������ ����� ����������:" << endl;
        print_array(array_of_numbers, size - 1);
        cout << "������ ������ �������� ������� ������� �����: " << binary_search(array_of_numbers, 0, size - 1, key) << endl;
        break;
    }
    default:
        cout << "������!\n"; 
        break;
    }

    return 0;
}