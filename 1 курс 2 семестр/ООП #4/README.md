Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## Простое наследование. Принцип подстановки.

Лабораторная работа №4 - Классы.

Базовый класс:
ПАРА_ЧИСЕЛ (PAIR)
Первое_число (first) - int
Второе_число (second) - int
Определить методы проверки на равенство и операцию перемножения полей.
Реализовать операцию вычитания пар по формуле (a,b)-(c,d)=(a-b,c-d)
Создать производный класс ПРОСТАЯ_ДРОБЬ(RATIONAL), с полями Числитель и Знаменатель. Переопределить операцию вычитания и определить операции сложения и умножения простых дробей.
## Код программы

>Pair.h
```C++
#pragma once

#include <iostream>

using namespace std;

  

class Pair

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

>4.cpp
```C++
#include <iostream>

#include "Pair.h"

#include "Rational.h"

using namespace std;

  

int main()

{

    Pair a(10,20);

    Pair b(30,20);

    Rational a1(28,37);

    Rational b1(18,29);

    bool c;

    c = a == b;

    cout << c << endl;

    a *= b;

    a -= b;

    a1 -= b1;

    a1 += b1;

    a1 *= b1;

}
```
# UML

<image src="4.png">

# Пример работы

```
0
300,400
-10,10
146/1073
1478/1073
504/1073
```

# Вопросы

1. Для чего используется механизм наследования?

- Для создания новых классов на основе существующих. Он позволяет классам наследовать свойства и методы других классов.

2. Каким образом наследуются компоненты класса, описанные со спецификатором public?

- наследуются также с модификатором public

3. Каким образом наследуются компоненты класса, описанные со спецификатором private?

- private компоненты класса остаются скрытыми и недоступными для других классов

4. Каким образом наследуются компоненты класса, описанные со спецификатором protected?

- наследуются с модификатором protected в производном классе

5. Каким образом описывается производный класс?

- `class <имя потомка> : <модификатор наследования> <имя родительского класса>{};`

6. Наследуются ли конструкторы?

- Да, но не вызываются автоматически

7. Наследуются ли деструкторы?

- Да, но не вызываются автоматически

8. В каком порядке конструируются объекты производных классов?

- 1. Вызывается конструктор базового класса.
    2. Конструируются члены базового класса.
    3. Вызывается конструктор производного класса.
    4. Конструируются члены производного класса.

9. В каком порядке уничтожаются объекты производных классов?

- 1. Вызывается деструктор производного класса.
    2. Разрушаются члены производного класса.
    3. Вызывается деструктор базового класса.
    4. Разрушаются члены базового класса.

10. Что представляют собой виртуальные функции и механизм позднего связывания?

- Виртуальные функции предназначенные для переопределения в производных классах. Механизм позднего связывания используется для разрешения вызова виртуальных функций во время выполнения программы.

11. Могут ли быть виртуальными конструкторы? Деструкторы?

- Только деструкторы.

12. Наследуется ли спецификатор virtual?

- нет, но его использование в производном классе позволяет переопределить функцию как виртуальную.

13. Какое отношение устанавливает между классами открытое наследование?

- производный класс наследует все открытые члены базового класса (поля, методы) и может использовать их в своем собственном контексте.

14. Какое отношение устанавливает между классами закрытое наследование?

- При закрытом наследовании, все публичные и защищенные члены базового класса становятся частными членами производного класса.

15. В чем заключается принцип подстановки?

- Принцип подстановки заключается в том, что объект производного класса может использоваться везде, где используется объект базового класса.

16. Имеется иерархия классов. Какие компонентные данные будет иметь объект х?

```c
class Student
{
	int age;
public:
	string name;
	...
};
class Employee : public Student
{
protected:
	string post;
	...
};
class Teacher : public Employee
{
	protected: int stage;
	...
};

Teacher x;
```

- public: name / protected: post, stage

17. Для классов Student, Employee и Teacher написать конструкторы без параметров.

```c
class Student {
public:
    Student() {
		age = 0;
		name = "";
	}
};


class Employee : public Student {
public:
    Employee() : Student() {
		post = "";
	}
};


class Teacher : public Employee {
public:
    Teacher() : Employee() {
		stage = 0;
	}
};
```

18. Для классов Student, Employee и Teacher написать конструкторы с параметрами.

```c
class Student {
public:
    Student(int age, std::string name) {
		this -> age = age;
		this -> name = name;
	}
};


class Employee : public Student {
public:
    Employee(std::string post) : Student(age, name) {
		this -> post = post;
	}
};


class Teacher : public Employee {
public:
    Teacher(int stage) : Employee(post) {
		this -> stage = stage;
	}
};
```

19. Для классов Student, Employee и Teacher написать конструкторы копирования.

```c
class Student {
public:
    Student(const Student& student) {
		age = student.age;
		name = student.name;
	}
};


class Employee : public Student {
public:
    Employee(const Employee& employee) {
		post = employee.post;
	}
};


class Teacher : public Employee {
public:
    Teacher(const Teacher& teacher) {
		stage = teacher.stage;
	}
};
```

20. Для классов Student, Employee и Teacher определить операцию присваивания.

```c
Student operator=(const Student& student) {
    age = student.age;
	name = student.name;
	return *this;
}


Employee operator=(const Employee& employee) {
	name = employee.name;
	post = employee.post;
	return *this;
}


Teacher operator=(const Teacher& teacher) {

	name = teacher.name;
	post = teacher.post;
	stage = teacher.stage;
	return *this;
}
```