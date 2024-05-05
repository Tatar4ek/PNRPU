#pragma once
#include <iostream>

class Iterator
{
    friend class Set;
private:
    int* current;

public:
    Iterator(int* ptr) : current(ptr) {}

    Iterator& operator++()
    {
        ++current;
        return *this;
    }

    Iterator& operator--()
    {
        --current;
        return *this;
    }

    int& operator*()
    {
        return *current;
    }

    bool operator!=(const Iterator& other) const
    {
        return current != other.current;
    }
};