Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## АТД. Контейнеры.

Лабораторная работа №6 - Классы.

Класс-контейнер МНОЖЕСТВО с элементами типа int.
Реализовать операции:
[] - доступа по индексу;
int() - определение размера вектора;
\* - пересечение множеств;
\-- - переход к предыдущему элементу ( с помощью класса-итератора )
## Код программы

>iterator.h
```C++
#pragma once

#include <iostream>

  

class Iterator

{

    friend class Set;

private:

    int* current; // Указатель на текущий элемент

  

public:

    Iterator(int* ptr) : current(ptr) {}

    // Перегрузка операторов для итератора

    Iterator& operator++() // Префиксный инкремент для перехода к следующему элементу

    {

        ++current;

        return *this;

    }

  

    Iterator& operator--() // Префиксный декремент для перехода к предыдущему элементу

    {

        --current;

        return *this;

    }

  

    int& operator*() // Доступ к значению, на которое указывает итератор

    {

        return *current;

    }

  

    bool operator!=(const Iterator& other) const // Проверка на неравенство итераторов

    {

        return current != other.current;

    }

};
```

>set.h
```C++
 #pragma once

 #include <iostream>

 #include "iterator.h"

 using namespace std;

  

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

    Set intersectionSet;

  

    for (int i = 0; i < size; i++)

    {

        if (s.isInSet(p[i]))

        {

            intersectionSet += p[i];

        }

    }

    return intersectionSet;

    }

  

    Iterator get_last()

    {

        if (size > 0) {

            return Iterator(&p[size - 1]);

        } else {

            return Iterator(nullptr);

        }

    }

    friend istream& operator >> (istream& in, Set& s)

    {

        cout << "Enter power: ";

        in >> s.size;

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

>6.cpp
```C++
#include <iostream>

#include "set.h"

using namespace std;

  

int main() {

    Set set1;

    cin >> set1;

    cout << set1[1] << endl;

    Iterator it = set1.get_last();

    --it;

    cout << *(it);

    return 0;

}
```
# UML

<image src="6.png">

# Пример работы

```
Enter power: 5
Enter chars: 3
5
7
8
9
Последний элемент: (Итератор находится на последнем элементе) 9
Предпоследний элемент: (Итератор перемещен назад на 1 элемент от последнего элемента) 8
```

# Вопросы

1. Что такое абстрактный тип данных? Привести примеры АТД.

- Абстрактный тип данных (Abstract Data Type, ADT) в программировании представляет собой математическую модель для организации данных и их операций, независимо от конкретной реализации. ADT определяет набор операций, которые могут быть выполнены над данными, но не определяет, как эти операции должны быть реализованы внутри структуры данных или объекта. Это позволяет отделять интерфейс (операции над данными) от реализации (внутренние детали хранения и обработки данных).

2. Привести примеры абстракции через параметризацию

- ```c
    template <typename T>
    class Box {
    private:
        T data;
    public:
        Box(T val) : data(val) {}
        T getData() { return data; }
    };
    
    int main() {
        Box<int> intBox(5);  // Создание объекта класса Box для int
        Box<double> doubleBox(3.14);  // Создание объекта класса Box для double
        return 0;
    }
    ```
    

3. Привести примеры абстракции через спецификацию.

- ```c
    class Shape {
    public:
        virtual double area() const = 0;  // Чисто виртуальная функция для вычисления площади
        virtual void draw() const = 0;  // Чисто виртуальная функция для отрисовки
        virtual ~Shape() {}  // Виртуальный деструктор
    };
    
    // Конкретный класс, реализующий интерфейс
    class Circle : public Shape {
    private:
        double radius;
    
    public:
        Circle(double r) : radius(r) {}
    
        double area() const override {
            return 3.14159 * radius * radius;
        }
    
        void draw() const override {
            std::cout << "Drawing a circle" << std::endl;
        }
    };
    
    // Конкретный класс, реализующий интерфейс
    class Rectangle : public Shape {
    private:
        double width;
        double height;
    
    public:
        Rectangle(double w, double h) : width(w), height(h) {}
    
        double area() const override {
            return width * height;
        }
    
        void draw() const override {
            std::cout << "Drawing a rectangle" << std::endl;
        }
    };
    
    int main() {
        Circle c(5);
        Rectangle r(3, 4);
        
        std::cout << "Circle area: " << c.area() << std::endl;  // Используем метод area через общий интерфейс Shape
        c.draw();  // Используем метод draw через общий интерфейс Shape
        
        std::cout << "Rectangle area: " << r.area() << std::endl;  // Используем метод area через общий интерфейс Shape
        r.draw();  // Используем метод draw через общий интерфейс Shape
        return 0;
    }
    ```
    

4. Что такое контейнер? Привести примеры.

- Контейнер в программировании - это тип, позволяющий инкапсулировать в себе объекты других типов. Примеры контейнеров: vector, list, map.

5. Какие группы операций выделяют в контейнерах?

- Операции доступа, Операции изменения размера, Операции итерации, Операции сравнения

6. Какие виды доступа к элементам контейнера существуют? Привести примеры.

- По индексу, По ключу, С помощью итераторов, Через методы поиска.

7. Что такое итератор?

- Итератор - это объект, который позволяет перебирать элементы контейнера и предоставляет доступ к каждому элементу в коллекции.

8. Каким образом может быть реализован итератор?

- Итератор может быть реализован как объект с методами для перемещения по контейнеру

9. Каким образом можно организовать объединение контейнеров?

- С помошью встроенных функций, с помощью итератора, использование алгоритмов и т. д.

10. Какой доступ к элементам предоставляет контейнер, состоящий из элементов «ключ-значение»?

- Контейнеры, состоящие из элементов "ключ-значение", такие как std::map, std::unordered_map в C++, предоставляют доступ к элементам через ключ.

11. Как называется контейнер, в котором вставка и удаление элементов выполняется на одном конце контейнера?

- stack

12. Какой из объектов (a,b,c,d) является контейнером?

```c
a. int mas = 10;
b. int mas;
c. struct {char name[30]; int age;} mas;
d. int mas[100].
```

- d

13. Какой из объектов (a,b,c,d) не является контейнером?

```c
a. int a[] = {1,2,3,4,5};
b. int mas[30];
c. struct {char name[30]; int age;} mas[30];
d. int mas.
```

- d

14. Контейнер реализован как динамический массив, в нем определена операция доступ по индексу. Каким будет доступ к элементам контейнера?

- Для доступа к элементам контейнера по индексу можно использовать оператор доступа к элементу "[]". Например, если у нас есть динамический массив с именем array, то доступ к элементу по индексу i будет выглядеть как array[i]

15. Контейнер реализован как линейный список. Каким будет доступ к элементам контейнера?

- указатель или итератор