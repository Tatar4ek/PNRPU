#pragma once
#include <iostream>
using namespace std;

class Pair
{
    private:
        int first;
        int second;
    public:
        Pair()
        {
            first = 0;
            second = 0;
        }
        virtual ~Pair()
        { 
        }
        virtual void set_first(int first)
        {
            this->first = first;
        }
        virtual void set_second(int second)
        {
            this->second = second;
        }
        virtual int get_first()
        {
            return first;
        }
        virtual int get_second()
        {
            return second;
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
        Pair operator*= (const Pair &other)
        {
            Pair temp;
            temp.first = this->first * other.first;
            temp.second = this->second * other.second;
            cout << temp << endl;
            return *this;
        }
        Pair operator-= (const Pair &other)
        {
            Pair temp;
            temp.first = this->first - this->second;
            temp.second = other.first - other.second;
            cout << temp << endl;
            return *this;
        }
};