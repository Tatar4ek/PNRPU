#include <iostream>
using namespace std;

void printArray(int arr[], int start, int end) {
    for (int i = start; i != end; i = (i + 1) % 10) { // 10 - ������ �������, �������� �� ������ ��������
        cout << arr[i] << " ";
    }
    cout << arr[end];  // ������ ���������� ��������
    cout << endl;
}
int main() {
    const int K = 3;  // ������ K
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // ������ ��������� �������
    const int N = sizeof(arr) / sizeof(arr[0]);  // ����������� ����� ��������� �������
    const int NEW_SIZE = N + 2;  // ����� ������ �������

    // ��������� ������ � ��������� �������� � ������
    int extendedArr[NEW_SIZE];
    extendedArr[0] = arr[N - 1];  // ��������� ��������� ������� � ������ �������
    for (int i = 0; i < N; i++) {
        extendedArr[i + 1] = arr[i];  // �������� �������� ������ � �������� ������������ �������
    }
    extendedArr[NEW_SIZE - 1] = arr[0];  // ��������� ������ ������� � ����� ������������ �������

    // ������������� ���������� ������, ������� � K-��� �������� � �� K-1 (�� ������ �����)
    printArray(extendedArr, K, K - 1);

    // ������������� ���������� ������, ������� � K-��� �������� � �� K+1 (�� ������ ������)
    printArray(extendedArr, K, (K + 1) % NEW_SIZE);

    return 0;
}