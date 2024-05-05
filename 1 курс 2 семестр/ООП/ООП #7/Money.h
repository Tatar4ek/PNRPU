#include <iostream>
#include "set.h"
using namespace std;
class Money
{
    private:
        long int rub;
        int kop;
    public:
        Money()
        {
            rub = 0;
            kop = 0;
        }
        Money(long int rub, int kop)
        {
            this->rub = rub;
            this->kop = kop;
        }
        Money(const Money &other)
        {
            this->rub = other.rub;
            this->kop = other.kop;
        }
        ~Money()
        {
        }
        long int get_rub()
        {
            return rub;
        }
        int get_kop()
        {
            return kop;
        }
        void set_rub(long int rub)
        {
            this->rub = rub;
        }
        void set_kop(int kop)
        {
            this->kop = kop;
        }
        void show()
        {
            std::cout << rub <<"," << kop << std::endl;
        }

        Money& operator = (const Money &other)
        {
            this->rub = other.rub;
            this->kop = other.kop;
            return *this;
        }
        
        Money& operator /= (const Money &other)
        {
            int temp1 = rub*100 + kop;
            int temp2 = other.rub*100 + other.kop;
            this->rub = (temp1/temp2) / 100;
            this->kop = (temp1/temp2) % 100;
            return *this;
        }

        Money& operator *= (float n)
        {
            int temp1 = rub*100 + kop;
            int temp2 = temp1*n / 100;
            this->rub = (temp1*n) / 100;
            this->kop = (temp1*n) - temp2 * 100;
            return *this;
        }

        friend istream &operator >> (istream&in, Money&other)
        {
            cout << "rub: "; in>>other.rub;
            cout << "kop: "; in>>other.kop;
            return in;
        } 

        friend ostream &operator << (ostream&out, const Money&other)
        {
            return (out<<other.rub<<","<<other.kop);
        }

};