#include <iostream>
#include <ctime>
using namespace std;


int partition(int arr[], int left, int right) {
    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (true) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i >= j) {
            return j;
        }
        swap(arr[i++], arr[j--]);
    }
}


void quick_sort_hoare(int arr[], int left, int right) { 
    if (left < right) {
        int pivot_index = partition(arr, left, right);
        quick_sort_hoare(arr, left, pivot_index);
        quick_sort_hoare(arr, pivot_index + 1, right);
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
    /*����� ����� ������ �������� ��� ����������� ������� � ������ ���������� �� �������� ������������ �������� � ���������� ���������� ���������, 
    ��� ��� ������������ ����������� ������� �� ����������. ������, ����� ���������, ��� � ������ ������ ������ ����� ����� �������� ������������� 
    ������������������ �� ��� ��������������� ��� ����� ��������������� ��������.*/
    setlocale(LC_ALL, "RUS");
    const int SIZE = 25;
    int array_of_numbers[SIZE];
    
    for (int i = 0; i < SIZE; i++) {
        array_of_numbers[i] = 1 + rand() % 1024;
    }
    cout << "������ ����� ���������� ���������� ������ �������:" << endl;
    print_array(array_of_numbers, SIZE);
    
    quick_sort_hoare(array_of_numbers, 0, SIZE - 1);
    cout << "������ ����� ����������:" << endl;
    print_array(array_of_numbers, SIZE);

    return 0;
}