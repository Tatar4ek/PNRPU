#pragma once
#include <iostream>

template<typename T>
class Set {
private:
    T* data;
    int size;

public:
    Set() : data(nullptr), size(0) {}

    ~Set() {
        delete[] data;
    }

    void add(T value) {
        if (!contains(value)) {
            T* new_data = new T[size + 1];
            for (int i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            new_data[size] = value;
            size++;
            delete[] data;
            data = new_data;
        }
    }

    bool contains(T value) const {
        for (int i = 0; i < size; ++i) {
            if (data[i] == value) {
                return true;
            }
        }
        return false;
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    operator int() const {
        return size;
    }

    Set<T> operator*(const Set<T>& other) const {
        Set<T> result;
        for (int i = 0; i < size; ++i) {
            if (other.contains(data[i])) {
                result.add(data[i]);
            }
        }
        return result;
    }

    void print() const {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};

