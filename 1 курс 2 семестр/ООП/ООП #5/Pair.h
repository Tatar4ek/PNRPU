#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

class Pair : public Object
{
    protected:
        int first;
        int second;
    public:
        Pair()
        {
            first = 0;
            second = 0;
        }
        ~Pair()
        { 
        }
        void set_first(int first)
        {
            this->first = first;
        }
        void set_second(int second)
        {
            this->second = second;
        }
        int get_first()
        {
            return first;
        }
        int get_second()
        {
            return second;
        }
        void print()
        {
            cout << first << "," << second << endl;
        }
        Pair(int first, int second)
        {
            this->first = first;
            this->second = second;
        }
        Pair (const Pair &other)
        {
            this->first = other.first;
            this->second = other.second;
        }
        friend ostream &operator<< (ostream&out, const Pair &other)
        {
            return(out<<other.first<<","<<other.second);
        }
        friend istream &operator>> (istream&in, Pair &other)
        {
            cout<<"first = "; in>>other.first;
            cout<<"second = "; in>>other.second;
            return in;
        }
        bool operator== (const Pair &other)
        {
            return (this->first == other.first && this->second == other.second);
        }
        Pair &operator*= (const Pair &other)
        {
            this->first *= other.first;
            this->second *= other.second;
            return *this;
        }
        Pair &operator-= (const Pair &other)
        {
            this->first -= other.first;
            this->second -= other.second;
            return *this;
        }
};