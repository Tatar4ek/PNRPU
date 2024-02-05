#include <iostream>
using namespace std;

void printArray(int arr[], int start, int end) {
    for (int i = start; i != end; i = (i + 1) % 10) { // 10 - размер массива, замените на нужное значение
        cout << arr[i] << " ";
    }
    cout << arr[end];  // печать последнего элемента
    cout << endl;
}
int main() {
    const int K = 3;  // индекс K
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  // пример исходного массива
    const int N = sizeof(arr) / sizeof(arr[0]);  // определение длины исходного массива
    const int NEW_SIZE = N + 2;  // новый размер массива

    // ƒобавл€ем первый и последний элементы в кольцо
    int extendedArr[NEW_SIZE];
    extendedArr[0] = arr[N - 1];  // добавл€ем последний элемент в начало массива
    for (int i = 0; i < N; i++) {
        extendedArr[i + 1] = arr[i];  // копируем исходный массив в середину расширенного массива
    }
    extendedArr[NEW_SIZE - 1] = arr[0];  // добавл€ем первый элемент в конец расширенного массива

    // –аспечатываем полученный массив, начина€ с K-ого элемента и до K-1 (по кольцу влево)
    printArray(extendedArr, K, K - 1);

    // –аспечатываем полученный массив, начина€ с K-ого элемента и до K+1 (по кольцу вправо)
    printArray(extendedArr, K, (K + 1) % NEW_SIZE);

    return 0;
}