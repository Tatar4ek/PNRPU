#include <iostream>
using namespace std;
 
class someclass
{
private:
    double first, second, x;
public:
    someclass(double a, double b)
    {
        first = a;
        second = b;
    }
 
    double function(double x)
    {
        int A = first;
        int B = second;
        return A*x + B;
    }
};
 
int main()
{
    setlocale(LC_ALL,"RUS");
    double first,second,x;
    cout << "\n������� �������� first="; cin >> first;
    cout << "\n������� �������� second="; cin >> second;
    cout << "\n������� �������� x="; cin >> x;
    someclass t(first,second);
    cout << t.function(x) << endl;
}