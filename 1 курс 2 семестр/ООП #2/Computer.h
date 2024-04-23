#include <iostream>
#include <string>
using namespace std;
class Computer
{
private:
    string processor;
    int ram;
    int drive;
public:
Computer()
{
    processor = "";
    ram = 0;
    drive = 0;
    cout << "Конструктор без параметров" << endl;
}

Computer(string P, int R, int D)
{
    processor = P;
    ram = R;
    drive = D;
    cout << "Конструктор с" << endl;
}

Computer(const Computer &c)
{
    processor = c.processor;
    ram = c.ram;
    drive = c.drive;
    cout << "Конструктор копирования" << endl;
}

~Computer()
{
    cout << "Деструктор" << endl;
}

string get_processor()
{
    return processor;
}

int get_ram()
{
    return ram;
}

int get_drive()
{
    return drive;
}

void set_processor(string P)
{
    processor = P;
}

void set_ram(int R)
{
    ram = R;
}

void set_drive(int D)
{
    drive = D;
}

void show()
{
    cout << "Процессор: " << processor<<endl;
    cout << "ОЗУ= " <<ram<<endl;
    cout << "ЖД= "<<drive<<endl;
}
};