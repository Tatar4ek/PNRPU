#include <iostream>
using namespace std;


void shell_sort(int arr[], int size) {
    for (int h = size / 2; h > 0; h /= 2) {
        for (int i = h; i < size; i++) {
            int tmp = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > tmp; j -= h) {
                arr[j] = arr[j - h];
            }
            arr[j] = tmp;
        }
    }
}


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
    /*���������� ����� �������� ����������� ����� ��� ��������, ������� �������� ������������� ��� ����� ������������ ���������, 
    ����� ��� ��������������� ����� ��� ����� ��������������� �����. ��� ������� � ���, ��� ���������� ����� ���������� 
    ��� ���������� "���������� ���������", ������� �������� ������� �� �������� ��������������� ��������, ��� �� ��������� ������������.*/
    setlocale(LC_ALL, "RUS");
    const int SIZE = 25;
    int array_of_numbers[SIZE] = {2, 2, 3, 1, 1, 3, 6, 6, 7, 1, 1, 2, 8, 8, 4, 8, 9, 9, 3, 3, 3, 4, 1, 2, 7};
    cout << "������ �������� ��������� �������:" << endl;
    print_array(array_of_numbers, SIZE);
    
    shell_sort(array_of_numbers, SIZE);
    cout << "������ ����� ����������:" << endl;
    print_array(array_of_numbers, SIZE);

    return 0;
}