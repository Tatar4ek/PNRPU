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
    cout << "����������� ��� ����������" << endl;
}

Computer(string P, int R, int D)
{
    processor = P;
    ram = R;
    drive = D;
    cout << "����������� �" << endl;
}

Computer(const Computer &c)
{
    processor = c.processor;
    ram = c.ram;
    drive = c.drive;
    cout << "����������� �����������" << endl;
}

~Computer()
{
    cout << "����������" << endl;
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
    cout << "���������: " << processor<<endl;
    cout << "���= " <<ram<<endl;
    cout << "��= "<<drive<<endl;
}
};