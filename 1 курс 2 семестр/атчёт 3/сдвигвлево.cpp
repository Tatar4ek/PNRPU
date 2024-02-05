#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int n = 8;
	int k, temp;
	cin >> k;
	int a[n];
	for (int i = 0; i < n; i++) {
		a[i] = rand();
		cout << a[i] << endl;
	}
	for (int i = 0; i < k; i++) {
		a[0] = temp;
		for (int j = 0; j < n - 1; j++) {
			a[j] = a[j + 1];
		}
		temp = a[n - 1];
	}
	cout << "||||";
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}
