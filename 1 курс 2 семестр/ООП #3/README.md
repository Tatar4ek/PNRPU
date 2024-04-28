Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## Перегрузка операций.

Лабораторная работа №3 - Классы.

Создать класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
- деление сумм,
- умножение суммы на дробное число.
## Код программы

>Money.h
```C++
#include <iostream>

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

  

        friend istream& operator >> (istream&in, Money&other)

        {

            cout << "rub: "; in>>other.rub;

            cout << "kop: "; in>>other.kop;

            return in;

        }

  

        friend ostream&operator << (ostream&out, const Money&other)

        {

            return (out<<other.rub<<","<<other.kop);

        }

  

};
```

>3.cpp
```C++
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

    cout<<"Результат деления сумм: " << m <<endl;

    cout<<"Результат умножения на дробное число 3.4: " << q <<endl;

    return 0;

}
```
# UML

<image src="3.png">

# Пример работы

```
rub: 20
kop: 40
rub: 10
kop: 20
Результат деления сумм: 0,2
Результат умножения на дробное число 3.4: 34,68
```

# Вопросы

1. Для чего используются дружественные функции и классы?

- Они могут получить доступ к закрытым и защищенным членам класса, к которому они дружественны

2. Сформулировать правила описания и особенности дружественных функций.

- Имеют доступ ко всем полям и методам класса, могут быть определены в другом классе.

3. Каким образом можно перегрузить унарные операции?

- ```c
    // бинарный оператор
    ReturnType operator Op(Type right_operand);
    // унарный оператор
    ClassType& operator Op();
    ```
    

4. Сколько операндов должна иметь унарная функция-операция, определяемая внутри класса?

- ноль или один

5. Сколько операндов должна иметь унарная функция-операция, определяемая вне класса?

- должна иметь один операнд в явном виде

6. Сколько операндов должна иметь бинарная функция-операция, определяемая внутри класса?

- должна иметь один-два операнда в явном виде

7. Сколько операндов должна иметь бинарная функция-операция, определяемая вне класса?

- два операнда в явном виде

8. Чем отличается перегрузка префиксных и постфиксных унарных операций?

- ```c
    // префиксные операторы
    Counter operator++ ();
    // постфиксные операторы
    Counter operator++ (int)
    ```
    

9. Каким образом можно перегрузить операцию присваивания?

- ```c
    Type operator= ()
    ```
    

10. Что должна возвращать операция присваивания?

- ссылку на объект

11. Каким образом можно перегрузить операции ввода-вывода?

- вне класса как дружественную функцию

12. В программе описан класс и определен объект этого класса. Каким образом, компилятор будет воспринимать вызов функции-операции?

```c
class Student
{
	Student& operator++();
};
// и определен объект этого класса
Student s;
// Выполняется операция
++s;
```

- будет вызван operator++() внутри класса Student, возвращаемый тип данных: ссылка на Student

13. В программе описан класс. Каким образом, компилятор будет воспринимать вызов функции-операции?

```c
class Student
{
	friend Student& operator ++( Student&);
};
// и определен объект этого класса
Student s;
// Выполняется операция
++s;
```

- будет вызвана дружественная функция operator++(Student&), возвращаемый тип данных: ссылка на Student

14. В программе описан класс. Каким образом, компилятор будет воспринимать вызов функции-операции?

```c
class Student
{
	bool operator<(Student &P);
};
// и определены объекты этого класса
Student a,b;
// Выполняется операция
cout << a < b;
```

- будет вызвана bool operator<(Student &P), возвращаемый тип данных: bool

15. В программе описан класс. Каким образом, компилятор будет воспринимать вызов функции-операции?

```c
class Student
{
	friend bool operator >(const Person&, Person&)
};
// и определены объекты этого класса
Student a,b;
// Выполняется операция
cout << a > b;
```

- будет вызвана дружественная функция operator >(const Person&, Person&), возвращаемый тип данных: bool