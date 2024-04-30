#include <iostream>
#include "set.h"
#include "Money.h"
using namespace std;

int main() {
    Set<int> set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set<int> set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);

    Set<int> set3 = set1 * set2;

    cout << "Elements of set1: ";
    set1.print();

    cout << "Elements of set2: ";
    set2.print();

    cout << "Intersection of set1 and set2: ";
    set3.print();

    // Example with a different type
    Set<char> charSet1;
    charSet1.add('a');
    charSet1.add('b');
    charSet1.add('c');

    Set<char> charSet2;
    charSet2.add('b');
    charSet2.add('c');
    charSet2.add('d');

    Set<char> charSet3 = charSet1 * charSet2;

    cout << "Elements of charSet1: ";
    charSet1.print();

    cout << "Elements of charSet2: ";
    charSet2.print();

    cout << "Intersection of charSet1 and charSet2: ";
    charSet3.print();

    return 0;
}
