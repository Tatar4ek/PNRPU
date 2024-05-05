Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## Обработка исключительных ситуаций

Лабораторная работа №9 - Классы.

Класс-контейнер МНОЖЕСТВО с элементами типа int.
Реализовать операции:
[] - доступа по индексу;
int() - определение размера вектора;
\* - пересечение множеств;
\-- - удаление элемента из множества.
## Код программы

>error.h
```C++
#pragma once

#include <string>

#include <iostream>

  

using namespace std;

  

class Error

{

public:

    virtual void what() {};

};

  

class IndexError : public Error

{

protected:

    string msg;

  

public:

    IndexError()

    {

        msg = "Index Error\n";

    }

  

    virtual void what()

    {

        cout << msg;

    }

};

  

class SizeError : public Error

{

protected:

    string msg;

  

public:

    SizeError()

    {

        msg = "size error\n";

    }

  

    virtual void what()

    {

        cout << msg;

    }

};

  

class MaxSizeError : public SizeError

{

protected:

    string msg_;

  

public:

    MaxSizeError()

    {

        SizeError();

        msg_ = "size>MAXSIZE\n";

    }

  

    virtual void what()

    {

        cout << msg << msg_;

    }

};

  

class EmptySizeError : public SizeError

{

protected:

    string msg_;

  

public:

    EmptySizeError()

    {

        SizeError();

        msg_ = "Vector is empty\n";

    }

  

    virtual void what()

    {

        cout << msg << msg_;

    }

};

  

class IndexError1 : public IndexError

{

protected:

    string msg_;

  

public:

    IndexError1()

    {

        IndexError();

        msg_ = "index <0\n";

    }

  

    virtual void what()

    {

        cout << msg << msg_;

    }

};

  

class IndexError2 : public IndexError

{

protected:

    string msg_;

  

public:

    IndexError2()

    {

        IndexError();

        msg_ = "index>size\n";

    }

  

    virtual void what()

    {

        cout << msg << msg_;

    }

};
```

>set.h
```C++
#pragma once

#include <iostream>

#include "error.h"

using namespace std;

  

const int max_size = 20;

class Set

{

    int size;

    int count;

    int* p;

public:

   Set (const Set &other)

    {

        this->size = other.size;

        this->count = other.count;

    }

    Set ()

    {

        size = 0;

        count = 0;

    }

    ~Set()

    {

        delete[]p;

    }

    int getSize() const

    {

        return size;

    }

    int getCount() const

    {

        return count;

    }

    void setSize(int size)

    {

        this->size = size;

        if (size > max_size)

        {

            throw MaxSizeError();

        }

    }

    void setCount(int count)

    {

        this->count = count;

    }

    int& operator[] (int index)

    {

    if (index >= 0 && index < size)

    {

        return p[index];

    }

    }

    bool isInSet(const int& n) const

    {

        for (int i = 0; i < size; i++)

            if (p[i] == n) return true;

        return false;

    }

    Set& operator = (const Set& s)

    {

        size = s.size;

        p = new int[count];

        return *this;

    }

    Set& operator += (const int& s)

    {

    if (isInSet(s)) return *this;

    int* tmp = new int[size + 1];

    for (int i = 0; i < size; i++)

    {

        tmp[i] = p[i];

    }

    tmp[size] = s;

    size++;

    delete[] p;

    p = tmp;

    return *this;

    }

  

    Set operator * (const Set& s) const

    {

    Set tmp;

  

    for (int i = 0; i < size; i++)

    {

        if (s.isInSet(p[i]))

        {

            tmp += p[i];

        }

    }

    return tmp;

    }

  

    Set& operator--(int value)

    {

        for (int i = 0; i < size; ++i) {

            if (p[i] == value) {

                for (int j = i; j < size - 1; ++j) {

                    p[j] = p[j + 1];

                }

                --size;

                break;

            }

        }

        return *this;

    }

  
  

    friend istream& operator >> (istream& in, Set& s)

    {

        cout << "Enter power: ";

        in >> s.size;

        if (s.size > max_size) {

            throw MaxSizeError();

        }

        s.p = new int[s.size];

        cout << "Enter chars: ";

        for (int i = 0; i < s.size; i++)

            in >> s.p[i];

        return in;

    }

  

    friend ostream& operator << (ostream& out, const Set& s)

    {

        out << "{ ";

        for (int i = 0; i < s.size - 1; i++)

            out << s.p[i] << ", ";

        out << s.p[s.size - 1] << " }";

        return out;

    }

};
```

>9.cpp
```C++
#include "set.h"
#include <iostream>
using namespace std;

int main()
{
    try
    {
    Set s1;
    cin >> s1;
    }

    catch (Error& e)
	{
		e.what();
	}

    return 0;
}

```
# UML

<image src="9.png">

# Пример работы

```
Enter power: 5
Enter chars: 3
4
6
8
5
Enter power: 30
size error
size>MAXSIZE
```

# Вопросы

1. Что представляет собой исключение в С++?

- Исключение в C++ представляет собой событие, которое возникает во время выполнения программы и влияет на нормальное выполнение кода.

2. На какие части исключения позволяют разделить вычислительный процесс? Достоинства такого подхода?

- Исключения позволяют разделить вычислительный процесс на блоки кода, которые могут возбуждать и обрабатывать исключения. Это позволяет отделить код, обрабатывающий ошибки, от основного бизнес-логики программы.

3. Какой оператор используется для генерации исключительной ситуации?

- Для генерации исключительной ситуации используется оператор throw.

4. Что представляет собой контролируемый блок? Для чего он нужен?

- Контролируемый блок - это блок кода, в котором может возникнуть исключение. Он нужен для определения места, где исключение может быть сгенерировано.

5. Что представляет собой секция-ловушка? Для чего она нужна?

- Секция-ловушка это блок кода, предназначенный для обработки исключений. Она нужна для указания действий, которые нужно выполнить, если произошло исключение.

6. Какие формы может иметь спецификация исключения в секции ловушке? В каких ситуациях используются эти формы?

- Спецификация исключения в секции-ловушке может быть указана как тип данных, так и ключевое слово catch (...), которое указывает на обработку всех типов исключений. Эти формы используются для определения того, какие исключения будут обработаны в данной секции-ловушке.

7. Какой стандартный класс можно использовать для создания собственной иерархии исключений?

- Для создания собственной иерархии исключений можно использовать стандартный класс std::exception или его наследников.

8. Каким образом можно создать собственную иерархию исключений?

- Чтобы создать собственную иерархию исключений, необходимо создать пользовательские классы исключений, которые будут наследоваться от стандартного класса std::exception или его наследников.

9. Если спецификация исключений имеет вид: void f1() throw(int, double); то какие исключения может прождать функция f1()?

- Функция f1() может обрабатывать исключения типа int или double.

10. Если спецификация исключений имеет вид: void f1() throw(); то какие исключения может прождать функция f1()?

- Функция f1() не может обрабатывать никакие исключения, так как спецификация имеет вид throw(), что указывает на отсутствие исключений.

11. В какой части программы может генерироваться исключение?

- Исключение может генерироваться в любой части программы, где это необходимо, например, в блоке try-блока кода или в функции, которая может потенциально вызвать ошибку.

12. Написать функцию, которая вычисляет площадь треугольника по трем сторонам (формула Герона). Функцию реализовать в 4 вариантах:
    
    1. без спецификации исключений;
    2. со спецификацией throw();
    3. с конкретной спецификацией с подходящим стандартным исключением;
    4. спецификация с собственным реализованным исключением.

```c
double area(double a, double b, double c) {
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
```

```c
double area(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw "Side length must be positive";
    }
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
```

```c
double area(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw std::invalid_argument("Side length must be positive");
    }
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
```

```c
class InvalidSideLengthException : public std::exception {
public:
    const char* what() const throw() {
        return "Side length must be positive";
    }
};

double area(double a, double b, double c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        throw InvalidSideLengthException();
    }
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}
```