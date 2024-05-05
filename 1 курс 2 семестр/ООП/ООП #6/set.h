 #pragma once
 #include <iostream>
 #include "iterator.h"
 using namespace std;

 class Set
{
    int size; 
    int count; 
    int* p; 
public:
   Set (const Set &other)
    {
        this->size = other.size;
        this->count = other.count;
    }
    Set ()
    {
        size = 0;
        count = 0;
    }
    ~Set()
    {
        delete[]p;
    }
    int getSize() const
    {
        return size;
    }
    int getCount() const
    {
        return count;
    }
    int& operator[] (int index)
    {
    if (index >= 0 && index < size)
    {
        return p[index];
    }
    }
     
    bool isInSet(const int& n) const
    {
        for (int i = 0; i < size; i++)
            if (p[i] == n) return true;
        return false; 
    }
     
    Set& operator = (const Set& s)
    { 
     
        size = s.size;
        p = new int[count];
        return *this;
    }
    Set& operator += (const int& s)
    {
    if (isInSet(s)) return *this;
    
    int* tmp = new int[size + 1];
    for (int i = 0; i < size; i++)
    {
        tmp[i] = p[i];
    }
    
    tmp[size] = s;
    size++;
    
    delete[] p;
    p = tmp;
    
    return *this;
    }

    Set operator * (const Set& s) const
    {
    Set intersectionSet;

    for (int i = 0; i < size; i++)
    {
        if (s.isInSet(p[i]))
        {
            intersectionSet += p[i];
        }
    }
    return intersectionSet;
    }

    Iterator get_last()
    {
        if (size > 0) {
            return Iterator(&p[size - 1]);
        } else {
            return Iterator(nullptr);
        }
    }
    friend istream& operator >> (istream& in, Set& s)
    {
        cout << "Enter power: ";
        in >> s.size;
        s.p = new int[s.size];
        cout << "Enter chars: ";
        for (int i = 0; i < s.size; i++)
            in >> s.p[i];
        return in;
    }

    friend ostream& operator << (ostream& out, const Set& s)
    {
        out << "{ ";
        for (int i = 0; i < s.size - 1; i++)
            out << s.p[i] << ", ";
        out << s.p[s.size - 1] << " }";
        return out;
    }
};