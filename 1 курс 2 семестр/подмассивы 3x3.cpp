#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n, m;
    cout << "������� ���������� ����� (N): ";
    cin >> n;
    cout << "������� ���������� �������� (M): ";
    cin >> m;

    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    cout << "������� �������� �������: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int max_sum = -1000; // ��������� �������� �����
    int x, y; // ���������� ������ �������� ���� ���������� � ������������ ������

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = 0; // ����� ��������� �������� ����������
            for (int k = i; k <= i + 2; k++) {
                for (int l = j; l <= j + 2; l++) {
                    sum += arr[k][l];
                }
            }
            if (sum > max_sum) {
                max_sum = sum;
                x = i;
                y = j;
            }
        }
    }

    cout << "��������� 3x3 � ������������ ������ ���������:" << endl;
    for (int i = x; i <= x + 2; i++) {
        for (int j = y; j <= y + 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}