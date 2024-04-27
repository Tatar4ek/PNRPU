#include <iostream>

class Money
{
    private:
        long rub;
        int kop;
    public:
        Money()
        {
            rub = 0;
            kop = 0;
            std::cout << "\n����������� ��� ����������: ";
        }
        Money(long r, int k)
        {
            this->rub = rub;
            this->kop = kop;
            std:: cout << "\n����������� � �����������: ";
        }
        Money(const Money &m)
        {
            rub = m.rub;
            kop = m.kop;
            std::cout << "\n����������� �����������: ";
        }
        ~Money()
        {
            std::cout<< "\n����� �����������";
        }
        long get_rub()
        {
            return rub;
        }
        int get_kop()
        {
            return kop;
        }
        void set_rub(long rub)
        {
            this->rub = rub;
        }
        void set_kop(int kop)
        {
            this->kop = kop;
        }
        void show()
        {
            std::cout << kop << std::endl << rub;
        }
        

};