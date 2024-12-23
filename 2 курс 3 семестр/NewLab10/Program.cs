using LibraryLab10;

namespace NewLab10
{
    public class Program
    {
        public static Organization[] CreateRandomOrganizations(Organization[] organizations)
        {
            for (int i = 5; i < 10; i++)
            {
                organizations[i].RandomInit();
            }
            return organizations;
        }

        public static Organization[] CreateOrganizations(Organization[] organizations)
        {
            //int size = Menu.InputInt("Введите размер массива");
            //var organizations = new Organization[size];
            string[] choose =
            {
                "Типы организаций\n",
                "1. Базовый тип (Организация)\n",
                "2. Страховая компания\n",
                "3. Судостроительная компания\n",
                "4. Завод\n",
                "5. Библиотека\n"
            };
            for (int i = 5; i < 10; i++)
            {
                foreach(var item in choose) Console.WriteLine(item);
                int action = Menu.InputInt($"Выберите тип для {i + 1} организации");
                switch(action)
                {
                    case 1:
                        organizations[i] = new Organization();
                        Console.WriteLine("Заполните данные организации: ");
                        organizations[i].Init();
                        break;
                    case 2:
                        organizations[i] = new InsuranceCompany();
                        Console.WriteLine("Заполните данные организации: ");
                        organizations[i].Init();
                        break;
                    case 3:
                        organizations[i] = new ShipCompany();
                        Console.WriteLine("Заполните данные организации: ");
                        organizations[i].Init();
                        break;
                    case 4:
                        organizations[i] = new Factory();
                        Console.WriteLine("Заполните данные организации: ");
                        organizations[i].Init();
                        break;
                    case 5:
                        organizations[i] = new Library();
                        Console.WriteLine("Заполните данные организации: ");
                        organizations[i].Init();
                        break;
                }
            }
            return organizations;
        }

        public static void PrintVirtualOrganizations(Organization[] organizations)
        {
            if (organizations is null || organizations.Length == 0)
            {
                Console.WriteLine("Массив пуст!");
                return;
            }
            for (int i = 0; i < organizations.Length; i++)
            {
                Console.WriteLine($"{i+1} Организация ");
                Console.WriteLine(organizations[i].GetType());
                organizations[i].Show();
                Console.WriteLine();
            }
        }

        public static void PrintNotVirtualOrganizations(Organization[] organizations)
        {
            if (organizations is null || organizations.Length == 0)
            {
                Console.WriteLine("Массив пуст!");
                return;
            }
            for (int i = 0; i < organizations.Length; i++)
            {
                Console.WriteLine($"{i+1} Организация ");
                Console.WriteLine(organizations[i].GetType());
                organizations[i].OrgShow();
            }
        }

        public static void SortComparable(Organization[] organizations)
        {
            Array.Sort(organizations);
            Console.WriteLine("Отсортированный массив по количеству работников");
            PrintVirtualOrganizations(organizations);
        }

        public static void SortCompareEmployees(Organization[] organizations)
        {
            Array.Sort(organizations, new SortByEmployees());
            Console.WriteLine("Отсортированный массив по количеству работникв");
            PrintVirtualOrganizations(organizations);
        }

        public static Organization? BinarySearchName(Organization[] organizations, string? target)
        {
            Array.Sort(organizations);
            if (target == null) return null;
            int left = 0;
            int right = organizations.Length - 1;
            while (left <= right)
            {
                int mid = (left+right) / 2;
                int compareResult = organizations[mid].Name.CompareTo(target);
                if (compareResult == 0) return organizations[mid];
                if (compareResult < 0) left = mid + 1;
                else right = mid - 1;
            }
            return null;
        }

        public static void ShowInit()
        {
            int action;
            string[] choose =
            {
                "Типы организаций\n",
                "1. Базовый тип (Организация)\n",
                "2. Страховая компания\n",
                "3. Судостроительная компания\n",
                "4. Завод\n",
                "5. Библиотека\n",
                "6. Человек (Класс не из иерархии)\n"
            };
            Console.WriteLine("Интерфейс IInit");
            IInit[] objects =
            {
                new Organization(),
                new ShipCompany(),
                new Factory(),
                new Library(),
                new InsuranceCompany(),
                new Person(), // Класс не из иерархии
                new Organization()
            };
            int count = 0;
            foreach(var item in objects)
            {
                Console.WriteLine($"Создается объект под номером {++count}");
                item.GetType();
                item.RandomInit();
                Console.WriteLine(item + "\n");
            }

            Console.WriteLine("Добавьте свой элемент массива: ");
            foreach(var row in choose)
                Console.WriteLine(row);
            action = Menu.InputInt("Выберите класс объекта: ");
            switch (action)
            {
                case 1:
                    objects[objects.Length - 1] = new Organization();
                    Console.WriteLine("Заполните данные организации: ");
                    objects[objects.Length - 1].Init();
                    break;
                case 2:
                    objects[objects.Length - 1] = new InsuranceCompany();
                    Console.WriteLine("Заполните данные организации: ");
                    objects[objects.Length - 1].Init();
                    break;
                case 3:
                    objects[objects.Length - 1] = new ShipCompany();
                    Console.WriteLine("Заполните данные организации: ");
                    objects[objects.Length - 1].Init();
                    break;
                case 4:
                    objects[objects.Length - 1] = new Factory();
                    Console.WriteLine("Заполните данные организации: ");
                    objects[objects.Length - 1].Init();
                    break;
                case 5:
                    objects[objects.Length - 1] = new Library();
                    Console.WriteLine("Заполните данные организации: ");
                    objects[objects.Length - 1].Init();
                    break;
                case 6:
                    objects[objects.Length - 1] = new Person();
                    Console.WriteLine("Заполните данные человека: ");
                    objects[objects.Length - 1].Init();
                    break;
            }
            Console.WriteLine("Конечный массив интерфейса IInit\n");
            foreach (var obj in objects)
                Console.WriteLine(obj + "\n");
        }

        public static void ShowCloneAndCopy()
        {
            var employees = new Employee[3];
            employees[0] = new Employee("Андрей", new Company("Microsoft"));
            employees[1] = (Employee)employees[0].Clone();
            employees[2] = (Employee)employees[0].ShallowCopy();
            foreach(var emp in employees)
                Console.WriteLine(emp);
            employees[2].Work.Name = "Valve";
            Console.WriteLine("Поле объекта employees[2].Work.Name было изменено с Microsoft на Valve");
            foreach (var emp in employees)
                Console.WriteLine(emp);

        }
        
        public static void PressAnyBtn()
        {
            Console.WriteLine("Нажмите любую кнопку для выхода в меню");
            Console.ReadLine();
        }

        static void Main()
        {
            string? name;
            Organization[] organizations =
            {
                new Organization("ООО АКЦИОНЕРЫ", "УЛИЦА ПУШКИНА, Д.10", 50),
                new InsuranceCompany("РОСГОССТРАХ", "УЛИЦА ЕВГЕНИЯ, Д.20", 10, 100000),
                new ShipCompany("КОРАБЛЕСТРОЙ", "УЛИЦА МОРСКАЯ, Д.15", 120, 100),
                new Factory("ЗАВОДИК", "УЛИЦА ЗАВОДСКАЯ, Д.1", 200, 20000),
                new Library("НАУЧНАЯ БИБЛИОТЕКА ПНИПУ", "УЛИЦА КОМСОМОЛЬСКАЯ, Д.29", 48, 3000),
                new Organization(),
                new InsuranceCompany(),
                new ShipCompany(),
                new Factory(),
                new Library()
            };
            CreateRandomOrganizations(organizations);
            int action;
            bool isWork = true;
            string[] menu =
            {
                "МЕНЮ",
                "Первая Часть (Создание классов, массива объектов и просмотр массива)\n",
                "1. Пересоздать объекты массива",
                "2. Вывод организаций (Виртуальные функции)",
                "3. Вывод организаций (Не виртуальные функции)\n",
                "Вторая Часть (Выполнение заданных запросов)\n",
                "4. Выполнить запросы\n",
                "Третья часть (Реализация интерфейсов)\n",
                "5. Сортировка массива с помощью интерфейса IComparable (По названию)",
                "6. Сортировка массива с помощью интерфейса ICompare (По количеству сотрудников)",
                "7. Поиск элемента в массиве по названию организации (Бинарный поиск)",
                "8. Демонстрация интерфейса IInit",
                "9. Клонирование и поверхностное копирование объектов\n",
                "0. Завершить работу"
            };
            while(isWork)
            {
                foreach(var row in menu)
                    Console.WriteLine(row);
                action = Menu.InputInt("Введите действие");
                switch(action)
                {
                    case 1:
                        organizations = CreateRandomOrganizations(organizations);
                        Console.WriteLine("Объекты были успешно пересозданы!");
                        PressAnyBtn();
                        break;
                    case 2:
                        PrintVirtualOrganizations(organizations);
                        PressAnyBtn();
                        break;
                    case 3:
                        PrintNotVirtualOrganizations(organizations);
                        PressAnyBtn();
                        break;
                    case 4:
                        Console.WriteLine("Введите название организации (Вывод количества работников)");
                        name = Console.ReadLine();
                        Requests.EmployeesCount(organizations, name);
                        Console.WriteLine($"Количество библиотек в городе: {Requests.LibraryCount(organizations)}");
                        Console.WriteLine($"Количество книг во всех библиотеках: {Requests.BooksCount(organizations)}");
                        PressAnyBtn();
                        break;
                    case 5:
                        SortComparable(organizations);
                        PressAnyBtn();
                        break;
                    case 6:
                        SortCompareEmployees(organizations);
                        PressAnyBtn();
                        break;
                    case 7:
                        Console.WriteLine("Введите название организации для поиска");
                        string? orgName = Console.ReadLine();
                        var result = BinarySearchName(organizations, orgName);
                        if (result == null)
                            Console.WriteLine("Организации не найдено");
                        else
                            Console.WriteLine($"Найдена следующая организация\n{result}");
                        PressAnyBtn();
                        break;
                    case 8:
                        ShowInit();
                        PressAnyBtn();
                        break;
                    case 9:
                        ShowCloneAndCopy();
                        PressAnyBtn();
                        break;
                    case 0:
                        isWork = false;
                        break;
                }
            }
        }
    }
}
