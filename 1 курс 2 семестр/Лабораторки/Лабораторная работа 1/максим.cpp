#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "RUS");
	int a[100];
	const int n = 10;
	int s = 1;
	int j;
	int max;
	for (int i = 0; i < n; i++) {
		a[i] = rand() % 200 - 100;
	}
	max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			s = 1;
			j = i + 1;
		}
		else {
			if (a[i] == max) {
				s += 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
	cout << "Максимальный элемент: " << max << endl << "Кол-во максимальных элементов: " << s << endl << "Номер элемента массива: " << j;
	return 0;
}
