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
            throw out_of_range("»ндекс находитс€ вне size");
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
    system("chcp 1251");
    Set set1;
    set1.add(1);
    set1.add(2);
    set1.add(3);

    Set set2;
    set2.add(2);
    set2.add(3);
    set2.add(4);

    cout << "Ёлементы set1: ";
    set1.print();

    cout << "Ёлементы set2: ";
    set2.print();

    Set intersection = set1 * set2;

    cout << "–езультат пересечени€ set1 и set2: ";
    intersection.print();

    cout << "Ёлемент с индексом 1 в set1: " << set1[1] << endl;

    cout << "–азмер set1: " << int(set1) << endl;

    return 0;
}
