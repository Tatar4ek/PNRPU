#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	const int n = 7;
	int a[n];
	int p, q, temp;
	cin >> p;
	cin >> q;
	for (int i = 0; i < n; i++) {
		a[i] = rand();
		cout << a[i] << endl;
	}
	cout << "||||" << endl;
	while (p < q) {
		temp = a[p];
		a[p] = a[q];
		a[q] = temp;
		p++;
		q--;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << endl;
	}
}