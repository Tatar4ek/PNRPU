#pragma once
#include <iostream>
#include "Pair.h"
using namespace std;

class Rational : public Pair
{
    private:
        int chisl;
        int znam;
    public:
        Rational()
        {
            chisl = 0;
            znam = 0;
        }
        ~Rational()
        { 
        }
        void set_first(int chisl)
        {
            this->chisl = chisl;
        }
        void set_second(int znam)
        {
            this->znam = znam;
        }
        int get_first()
        {
            return chisl;
        }
        int get_second()
        {
            return znam;
        }
        Rational(int chisl, int znam)
        {
            this->chisl = chisl;
            this->znam = znam;
        }
        Rational (const Rational &other)
        {
            this->chisl = other.chisl;
            this->znam = other.znam;
        }
        friend ostream &operator<< (ostream&out, const Rational &other)
        {
            return(out<<other.chisl<<"/"<<other.znam);
        }
        friend istream &operator>> (istream&in, Rational &other)
        {
            cout<<"chisl = "; in>>other.chisl;
            cout<<"znam = "; in>>other.znam;
            return in;
        }
        Rational &operator-= (const Rational &other)
        {
            Rational temp;
            temp.chisl = this->chisl * other.znam - other.chisl * this->znam;
            temp.znam = this->znam * other.znam;
            cout<<temp<<endl;
            return *this;
        }
        Rational &operator*= (const Rational &other)
        {
            Rational temp;
            temp.chisl = this->chisl * other.chisl;
            temp.znam = this->znam * other.znam;
            cout << temp;
            return *this;
        }
        Rational &operator+= (const Rational &other)
        {
            Rational temp;
            temp.chisl = this->chisl * other.znam + other.chisl * this->znam;
            temp.znam = this->znam * other.znam;
            cout<<temp<<endl;
            return *this;
        }
};