Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## АТД. Контейнеры.

Лабораторная работа №6 - Классы.

Класс-контейнер МНОЖЕСТВО с элементами типа int.
Реализовать операции:
[] - доступа по индексу;
int() - определить размер вектора;
*- пересечение множеств;
-- - переход к предыдущему элементу (с помощью класс-итератора)
## Код программы

>6.cpp
```C++
#include <iostream>

  

using namespace std;

  

class Set {

private:

    int* data;

    int size;

  

public:

    Set()

    {

    data = nullptr;

    size = 0;

    }

    ~Set() {

        delete[] data;

    }

  

    void add(int value) {

        if (!contains(value)) {

            int* new_data = new int[size + 1];

            for (int i = 0; i < size; ++i) {

                new_data[i] = data[i];

            }

            new_data[size] = value;

            size++;

            delete[] data;

            data = new_data;

        }

    }

  

    bool contains(int value) const {

        for (int i = 0; i < size; ++i) {

            if (data[i] == value) {

                return true;

            }

        }

        return false;

    }

  

    int operator[](int index) const {

        if (index < 0 || index >= size) {

            throw out_of_range("Индекс находится вне size");

        }

        return data[index];

    }

  

    operator int() const {

        return size;

    }

  

    Set operator*(const Set& other) const {

        Set result;

        for (int i = 0; i < size; ++i) {

            if (other.contains(data[i])) {

                result.add(data[i]);

            }

        }

        return result;

    }

  

    void print() const {

        for (int i = 0; i < size; i++) {

            cout << data[i] << " ";

        }

        cout << endl;

    }

};

  

int main() {

    system("chcp 1251");

    Set set1;

    set1.add(1);

    set1.add(2);

    set1.add(3);

  

    Set set2;

    set2.add(2);

    set2.add(3);

    set2.add(4);

  

    cout << "Элементы set1: ";

    set1.print();

  

    cout << "Элементы set2: ";

    set2.print();

  

    Set intersection = set1 * set2;

  

    cout << "Результат пересечения set1 и set2: ";

    intersection.print();

  

    cout << "Элемент с индексом 1 в set1: " << set1[1] << endl;

  

    cout << "Размер set1: " << int(set1) << endl;

  

    return 0;

}
```
# UML

<image src="6.png">

# Пример работы

```
Элементы set1: 1 2 3
Элементы set2: 2 3 4
Результат пересечения set1 и set2: 2 3
Элемент с индексом 1 в set1: 2
Размер set1: 3
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