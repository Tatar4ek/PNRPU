Валинуров Ринат Наилевич

РИС-23-1б

# 7 Вариант задания

## Обработка исключительных ситуаций

Лабораторная работа №10 - Классы.

Создать класс Money для работы с денежными суммами. Число должно быть представлено двумя полями: типа long для рублей и типа int для копеек. Дробная часть числа при выводе на экран должна быть отделена от целой части запятой. Реализовать:
- сложение денежных сумм,
- вычитание денежных сумм,
Задание:
- Удалить все записи равные заданному значению.
- Увеличить все записи с заданным значением на 1 рубль 50 копеек.
- Добавить К записей после элемента с заданным номером.
## Код программы

>money.h
```C++
#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Money
{
public:
	int rub;
	int kop;

	Money() { rub = 0; kop = 0; };
	Money(int m, int s) { rub = m; kop = s; }
	Money(int s) { rub = 0; kop = s; }
	Money(const Money& t) { rub = t.rub; kop = t.kop; }
	~Money() {};

	void clear() { kop = 0; };
	int get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(int m) { rub = m; }
	void set_kop(int s) { kop = s; }

	Money& operator=(const Money&);
	Money& operator++();
	Money operator++(int);
	Money operator+(const Money&);
	Money operator-(const Money&);

	friend istream& operator>>(istream& in, Money& t);
	friend ostream& operator<<(ostream& out, const Money& t);
	friend fstream& operator>>(fstream& fin, Money& p);
	friend fstream& operator <<(fstream& fout, const Money& p);
};
```

>money.cpp
```C++
#include "Money.h"
#include <iostream>
#include <windows.h>

using namespace std;

Money& Money::operator=(const Money& t)
{
	if (&t == this)
		return *this;

	rub = t.rub;
	kop = t.kop;

	return *this;
}

Money& Money::operator++()
{
	int temp = rub * 100 + kop;
	temp++;

	rub = temp / 100;
	kop = temp % 100;

	return *this;
}

Money Money::operator ++(int)
{
	int temp = rub * 100 + kop;
	temp++;
	Money t(rub, kop);

	rub = temp / 100;
	kop = temp % 100;

	return t;
}

Money Money::operator+(const Money& t)
{
	int temp1 = rub * 100 + kop;
	int temp2 = t.rub * 100 + t.kop;

	Money p;

	p.rub = (temp1 + temp2) / 100;
	p.kop = (temp1 + temp2) % 100;

	return p;
}

Money Money::operator-(const Money& t)
{
	int temp1 = rub * 100 - kop;
	int temp2 = t.rub * 100 - t.kop;

	Money p;

	p.rub = (temp1 - temp2) / 100;
	p.kop = (temp1 - temp2) % 100;

	return p;
}

istream& operator>>(istream& in, Money& t)
{
	cout << "Enter Rubles: "; in >> t.rub;
	cout << "Enter Kop: "; in >> t.kop;

	return in;
}

ostream& operator<<(ostream& out, const Money& t)
{
	return (out << t.rub << "," << t.kop);
}

fstream& operator>>(fstream& fin, Money& p)
{
	fin >> p.rub;
	fin >> p.kop;

	return fin;
}
fstream& operator <<(fstream& fout, const Money& p)
{
	fout << to_string(p.rub) << "\n" << p.kop << "\n";

	return fout;
}
```

>10.cpp
```C++
#include "Money.h"
#include <iostream>
#include <fstream>
#include "fire_work.h"
#include <windows.h> 

using namespace std;

int main()
{
    Money p, p1, p2;
    int k, c;
    char file_name[30];

    do
    {
        cout << "\n1. Make file";
        cout << "\n2. Print file";
        cout << "\n3. Delete record from file";
        cout << "\n4. Add record to file";
        cout << "\n5. Change record in file";
        cout << "\n0. Exit\n";
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "file name ";
            cin >> file_name;
            k = make_file(file_name);

            if (k < 0)
                cout << "Can't make file";
            break;

        case 2:
            cout << "file name ";
            cin >> file_name;
            k = print_file(file_name);

            if (k == 0)
                cout << "Empty file\n";
            if (k < 0)
                cout << "Can't read file\n";
            break;

        case 3:
            cout << "file name ";
            cin >> file_name;
            int nom;
            cout << "nom ";
            cin >> nom;

            k = del_file(file_name, nom);

            if (k < 0)
                cout << "Can't read file";
            break;

        case 4:
            cout << "file name ";
            cin >> file_name;
            cout << "nom ";
            cin >> nom;
            cout << "New Money:";

            k = add_file(file_name, nom, p1);

            break;

        case 5:
            cout << "file name ";
            cin >> file_name;
            cout << "nom ";
            cin >> nom;
            cout << "New Money: ";
            cin >> p2;

            k = change_file(file_name, nom, p2);

            if (k < 0)
                cout << "\nCan't read file";
            if (k == 0)
                cout << "\nNot such record";
            break;
        }
    } while (c != 0);
    return 0;
}

```
# UML

<image src="10.png">

# Пример работы

```
1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
0. Exit
2
file name OOP10
20,85
35,58

1. Make file
2. Print file
3. Delete record from file
4. Add record to file
5. Change record in file
0. Exit
```

# Вопросы

1. Что такое поток?

- Поток (stream) в C++ - это последовательность данных, которые могут быть считаны или записаны в устройство ввода-вывода (как файл, консоль и т. д.).

2. Какие типы потоков существуют?

- Существуют типы потоков: ввода (input) и вывода (output).

3. Какую библиотеку надо подключить при использовании стандартных потоков?

- При использовании стандартных потоков надо подключить библиотеку .

4. Какую библиотеку надо подключить при использовании файловых потоков?

- При использовании файловых потоков надо подключить библиотеку .

5. Какую библиотеку надо подключить при использовании строковых потоков?

- При использовании строковых потоков надо подключить библиотеку .

6. Какая операция используется при выводе в форматированный поток?

- Для вывода в форматированный поток используется оператор "<<".

7. Какая операция используется при вводе из форматированных потоков?

- Для ввода из форматированных потоков используется оператор ">>".

8. Какие методы используются при выводе в форматированный поток?

- При выводе в форматированный поток используются методы, такие как setw(), setprecision() и т. д.

9. Какие методы используется при вводе из форматированного потока?

- При вводе из форматированного потока используются методы, такие как getline(), get() и т. д.

10. Какие режимы для открытия файловых потоков существуют?

- Режимы для открытия файловых потоков: ios::in, ios::out, ios::ate, ios::app, ios::binary, ios::trunc.

11. Какой режим используется для добавления записей в файл?

- Режим ios::app используется для добавления записей в файл.

12. Какой режим (комбинация режимов) используется в конструкторе ifstream file("f.txt")?

- Для ifstream file("f.txt") в конструкторе используется режим ios::in (по умолчанию).

13. Какой режим (комбинация режимов) используется в конструкторе fstream file("f.txt")?

- Для fstream file("f.txt") не используется конкретный режим, но по умолчанию используется режим ios::in|ios::out.

14. Какой режим (комбинация режимов) используется в конструкторе ofstream file("f.txt")?

- Для ofstream file("f.txt") используется режим ios::out (по умолчанию).

15. Каким образом открывается поток в режиме ios::out|ios::app?

- Поток в режиме ios::out|ios::app открывается для записи в конец файла.

16. Каким образом открывается поток в режиме ios::out |ios::trunc?

- Поток в режиме ios::out|ios::trunc открывается для записи с обрезанием файла до нулевой длины.

17. Каким образом открывается поток в режиме ios::out |ios::in|ios::trunc?

- Поток в режиме ios::out|ios::in|ios::trunc открывается для чтения и записи, с обрезанием файла до нулевой длины.

18. Каким образом можно открыть файл для чтения?

- Файл открывается для чтения с помощью ifstream file("filename", ios::in).

19. Каким образом можно открыть файл для записи?

- Файл открывается для записи с помощью ofstream file("filename", ios::out).

20. Привести примеры открытия файловых потоков в различных режимах.

- `ifstream input("file.txt");`
- `ofstream output("file.txt");`
- `fstream file("file.txt", ios::in | ios::out);`

21. Привести примеры чтения объектов из потока.

```c
ifstream input("file.txt");
int value;
while (input >> value) {
    // делаем что-то с прочитанным значением
}
input.close();
```

22. Привести примеры записи объектов в поток.

```c
ofstream output("file.txt");
int value = 10;
output << value;
output.close();
```

23. Сформулировать алгоритм удаления записей из файла.

```
1. Открыть файл в режиме чтения и записи.
2. Создать временный файл для сохранения неудаленных записей.
3. Прочитать записи из исходного файла, пропуская удаляемые записи.
4. Записать неудаленные записи во временный файл.
5. Удалить исходный файл.
6. Переименовать временный файл в имя исходного файла.
```

24. Сформулировать алгоритм добавления записей в файл.

```
1. Открыть файл в режиме добавления (append).
2. Записать новые записи в конец файла.
```

25. Сформулировать алгоритм изменения записей в файле.

```
1. Открыть файл в режиме чтения и записи.
2. Найти нужную запись в файле.
3. Изменить запись.
4. Записать измененные данные обратно в файл.
```