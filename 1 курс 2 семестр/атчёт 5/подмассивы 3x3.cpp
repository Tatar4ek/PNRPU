#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    int n, m;
    cout << "Ââåäèòå êîëè÷åñòâî ñòðîê (N): ";
    cin >> n;
    cout << "Ââåäèòå êîëè÷åñòâî ñòîëáöîâ (M): ";
    cin >> m;

    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
    }

    cout << "Ââåäèòå ýëåìåíòû ìàññèâà: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int max_sum = -1000; // ñòàðòîâîå çíà÷åíèå ñóììû
    int x, y; // êîîðäèíàòû ëåâîãî âåðõíåãî óãëà ïîäìàññèâà ñ ìàêñèìàëüíîé ñóììîé

    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {
            int sum = 0; // ñóììà ýëåìåíòîâ òåêóùåãî ïîäìàññèâà
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

    cout << "Ïîäìàññèâ 3x3 ñ ìàêñèìàëüíîé ñóììîé ýëåìåíòîâ:" << endl;
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
