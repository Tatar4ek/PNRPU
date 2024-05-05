Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## Наследование. Виртуальные функции. Полиморфизм.

Лабораторная работа №5 - Классы.

Базовый класс:
ПАРА_ЧИСЕЛ (PAIR)
Первое_число (first) - int
Второе_число (second) - int
Определить методы проверки на равенство и операцию перемножения полей.
Реализовать операцию вычитания пар по формуле (a,b)-(c,d)=(a-b,c-d)
Создать производный класс ПРОСТАЯ_ДРОБЬ(RATIONAL), с полями Числитель и Знаменатель. Переопределить операцию вычитания и определить операции сложения и умножения простых дробей.
## Код программы

>Object.h
```C++
#pragma once

#include <iostream>

  

class Object {

public:

    Object () {};

    ~Object () {};

    virtual void print() = 0;

};
```

>Vector.h
```C++
#include <iostream>

#include "Pair.h"

using namespace std;

class Vector

{

private:

    Object** vect;

    int size;

    int current_position;

  

public:

    Vector()

    {

        vect = 0;

        size = 0;

        current_position = 0;

    }

  

    Vector(int size)

    {

        vect = new Object* [size];

        this->size = size;

        current_position = 0;

    }

    ~Vector()

    {

        if(vect != 0)

        {

            delete vect;

        }

    }

    void add(Object*ptr)

    {

        if(current_position < size)

        {

            vect[current_position] = ptr;

            current_position++;

        }

    }

    friend ostream&operator<<(ostream&out, const Vector&v)

    {

        if(v.size == 0)

        {

            out << "\nВектор пустой.";

        }

        Object **ptr = v.vect;

        for(int i = 0; i < v.current_position; i++)

        {

            (*ptr) -> print();

            ptr++;

        }

        return out;

    }

};
```

>Pair.h
```C++
#pragma once
#include <iostream>
#include "Object.h"
using namespace std;

  

class Pair : public Object

{

    private:

        int first;

        int second;

    public:

        Pair()

        {

            first = 0;

            second = 0;

        }

        virtual ~Pair()

        {

        }

        virtual void set_first(int first)

        {

            this->first = first;

        }

        virtual void set_second(int second)

        {

            this->second = second;

        }

        virtual int get_first()

        {

            return first;

        }

        virtual int get_second()

        {

            return second;

        }

        Pair(int first, int second)

        {

            this->first = first;

            this->second = second;

        }

        Pair (const Pair &other)

        {

            this->first = other.first;

            this->second = other.second;

        }

        friend ostream &operator<< (ostream&out, const Pair &other)

        {

            return(out<<other.first<<","<<other.second);

        }

        friend istream &operator>> (istream&in, Pair &other)

        {

            cout<<"first = "; in>>other.first;

            cout<<"second = "; in>>other.second;

            return in;

        }

        bool operator== (const Pair &other)

        {

            return (this->first == other.first && this->second == other.second);

        }

        Pair operator*= (const Pair &other)

        {

            Pair temp;

            temp.first = this->first * other.first;

            temp.second = this->second * other.second;

            cout << temp << endl;

            return *this;

        }

        Pair operator-= (const Pair &other)

        {

            Pair temp;

            temp.first = this->first - this->second;

            temp.second = other.first - other.second;

            cout << temp << endl;

            return *this;

        }

};
```

>Rational.h
```C++
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
```

>5.cpp
```C++
#include <iostream>

#include "Pair.h"

#include "Rational.h"

#include "Vector.h"

#include "Object.h"

using namespace std;

  

int main()

{
    system("chcp 1251");

    Vector vect(5);

    Pair pair;

    cout<< "Введите два числа: " << endl;

    cin >> pair;

    Rational rational;

    cout << "Введите два числа: " << endl;

    cin >> rational;

  

    Object *ptr = &pair;

    vect.add(ptr);

    ptr = &rational;

    vect.add(ptr);

    cout << vect;

  

    cout << "Содержание вектора: " << endl;

    cout << vect;
}

```
# UML

<image src="5.png">

# Пример работы

```
Введите два числа:
first = 10
second = 20
Введите два числа:
chisl = 30
znam = 24
10,20
30/24
Содержание вектора:
10,20
30/24
```

# Вопросы

1. Какой метод называется чисто виртуальным? Чем он отличается от виртуального метода?

- Чисто виртуальный метод в C++ - это метод, который объявлен в базовом классе с ключевым словом "virtual" и равен 0. Он не имеет реализации в базовом классе, и поэтому должен быть переопределен в производных классах.

2. Какой класс называется абстрактным?

- В C++ абстрактным классом называется класс, в котором имеется хотя бы один чисто виртуальный метод.

3. Для чего предназначены абстрактные классы?

- Абстрактные классы в объектно-ориентированном программировании служат для создания общего интерфейса, который определяет методы, но не предоставляет их реализацию. Они используются для организации общей структуры и поведения для группы классов.

4. Что такое полиморфные функции?

- В C++ полиморфизм может реализовываться через виртуальные функции и перегрузку операторов. Это позволяет использовать разные реализации одного метода (или оператора) в зависимости от типа объекта.

5. Чем полиморфизм отличается от принципа подстановки?

- полиморфизм представляет способность использования изменяемой реализации методов, тогда как принцип подстановки означает, что подклассы могут быть использованы вместо своих суперклассов без изменения предположений и корректности программы.

6. Привести примеры иерархий с использованием абстрактных классов.

- ```c
    class Shape {
    public:
        virtual float area() const = 0;
        virtual ~Shape() {}
    };
    
    class Rectangle : public Shape {
    public:
        float area() const override {
            // реализация вычисления площади прямоугольника
        }
    };
    
    class Circle : public Shape {
    public:
        float area() const override {
            // реализация вычисления площади круга
        }
    };
    ```
    

7. Привести примеры полиморфных функций.

- ```c
    class Animal {
    public:
        virtual void makeSound() const {
            std::cout << "Some sound" << std::endl;
        }
    };
    
    class Dog : public Animal {
    public:
        void makeSound() const override {
            std::cout << "Woof! Woof!" << std::endl;
        }
    };
    
    class Cat : public Animal {
    public:
        void makeSound() const override {
            std::cout << "Meow! Meow!" << std::endl;
        }
    };
    
    void announceSound(const Animal& animal) {
        animal.makeSound(); // Вызов виртуальной функции, полиморфизм
    }
    
    int main() {
        Dog dog;
        Cat cat;
    
        announceSound(dog); // Woof! Woof!
        announceSound(cat); // Meow! Meow!
    
        return 0;
    }
    ```
    

8. В каких случаях используется механизм позднего связывания?

- Основной результат позднего связывания заключается в том, что программа может выбирать конкретную реализацию метода во время выполнения в зависимости от фактического типа объекта, что позволяет эффективно применять полиморфизм и создавать гибкие и расширяемые программы.