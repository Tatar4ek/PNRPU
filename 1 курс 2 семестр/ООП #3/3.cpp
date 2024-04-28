#include <iostream>
#include "Money.h"

int main()
{
    system("chcp 1251");
    Money m;
    Money q;
    cin>>m;
    cin>>q;
    m /= q;
    q *= 3.4;
    cout<<m<<endl;
    cout<<q<<endl;
    return 0;
}