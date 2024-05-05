#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Set
{
private:
    int size;
    int count;
    T* p;
public:
    Set(int s, T k)
    {
        size = s;
        count = 0;
        p = new T[size];
        for (int i = 0; i < size; i++)
        {
            p[i] = k;
        }
    
    }
    
    Set(const Set& other)
    {
        size = other.size;
        count = other.count;
        p = new T[size];
        for (int i = 0; i < size; i++)
        {
            p[i] = other.p[i];
        }
    }
    
    ~Set()
    {
        delete[] p;
        p = 0;
    }

    int getSize() const
    {
        return size;
    }

    int getCount() const
    {
        return count;
    }

    void setSize(int size)
    {
        this->size = size;
    }

    void setCount(int count)
    {
        this->count = count;
    }

    T& operator[](int index)
    {
        if (index >= 0 && index < size)
        {
            return p[index];
        }
    }

    bool isInSet(const T& n) const
    {
        for (int i = 0; i < size; i++)
        {
            if (p[i] == n)
            {
                return true;
            }
        }
        return false;
    }

    Set& operator=(const Set& s)
    {
        size = s.size;
        count = s.count;
        p = new T[count];
        for (int i = 0; i < size; ++i)
        {
            p[i] = s.p[i];
        }
        return *this;
    }

    Set& operator+=(const T& s)
    {
    if (isInSet(s))
    {
        return *this;
    }

    T* tmp = new T[size + 1];
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


    Set& operator+=(const T& s)
    {
    if (isInSet(s))
    {
        return *this;
    }

    T* tmp = new T[size + 1];
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


    Set operator*(const Set& s) const
    {
        Set tmp;

        for (int i = 0; i < size; i++)
        {
            if (s.isInSet(p[i]))
            {
                tmp += p[i];
            }
        }
        
        return tmp;
    }

    friend istream& operator>>(istream& in, Set& s)
    {
        cout << "Enter power: ";
        in >> s.size;
        s.p = new T[s.size];
        cout << "Enter elements: ";
        for (int i = 0; i < s.size; i++)
        {
            in >> s.p[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, const Set& s)
    {
        out << "{ ";
        for (int i = 0; i < s.size - 1; i++)
        {
            out << s.p[i] << ", ";
        }
        out << s.p[s.size - 1] << " }";
        return out;
    }
};
