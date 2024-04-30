#include <iostream>

using namespace std;

class Set {
private:
    int* data;
    int size;

public:
    Set()
    {
    data = nullptr; 
    size = 0;
    }
    ~Set() {
        delete[] data;
    }

    void add(int value) {
        if (!contains(value)) {
            int* new_data = new int[size + 1];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            new_data[size] = value;
            size++;
            delete[] data;
            data = new_data;
        }
    }

    bool contains(int value) const {
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                return true;
            }
        }
        return false;
    }

    int operator[](int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    operator int() const {
        return size;
    }

    Set operator*(const Set& other) const {
        Set result;
        for (int i = 0; i < size; ++i) {
            if (other.contains(data[i])) {
                result.add(data[i]);
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Set set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);

    Set set3 = set1 * set2;

    cout << "Elements of set1: ";
    set1.print();

    cout << "Elements of set2: ";
    set2.print();

    cout << "Intersection of set1 and set2: ";
    set3.print();

    return 0;
}
