#include <iostream>
using namespace std;
 
class someclass
{
private:
    double first, second, x;
public:
void setfirst(double A)
{
    first = A;
}
void setsecond(double B)
{
    second = B;
}
void setx(double valueX)
{
    x = valueX;
}
double function(double x)
{
    return first*x + second;
}
};
 
int main()
{
    setlocale(LC_ALL,"RUS");
    double first,second,x;
    cout << "\n¬ведите значение first="; cin >> first;
    cout << "\n¬ведите значение second="; cin >> second;
    cout << "\n¬ведите значение x="; cin >> x;
    someclass t;
    t.setfirst(first);
    t.setsecond(second);
    t.setx(x);
    cout << t.function(x) << endl;
}