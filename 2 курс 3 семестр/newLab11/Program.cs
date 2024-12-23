using System;
using LibraryLab10;

namespace newLab11
{
    public class Program
    {
        public static void DisplayCollectionTime(TestCollections test)
        {
            var firstElem = (Library)test.libraries.Peek().Clone();
            var centerElem = (Library)test.GetMiddleElement().Clone();
            var lastElem = (Library)test.GetLastElement().Clone();
            var newElem = new Library("Библиотека", "Улица пушкина", 100, 1000);
            Console.WriteLine("Время поиска первого элемента в коллекции Queue<Library>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.libraries, firstElem)}");
            Console.WriteLine("Время поиска среднего элемента в коллекции Queue<Library>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.libraries, centerElem)}");
            Console.WriteLine("Время поиска последнего элемента в коллекции Queue<Library>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.libraries, lastElem)}");
            Console.WriteLine("Время поиска элемента, не входящий в коллекцию Queue<Library>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.libraries, newElem)}");
            Console.WriteLine();
            Console.WriteLine("Время поиска первого элемента в коллекции Queue<string>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.librariesString, firstElem.ToString())}");
            Console.WriteLine("Время поиска среднего элемента в коллекции Queue<string>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.librariesString, centerElem.ToString())}");
            Console.WriteLine("Время поиска последнего элемента в коллекции Queue<string>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.librariesString, lastElem.ToString())}");
            Console.WriteLine("Время поиска элемента, не входящего в коллекцию Queue<string>");
            Console.WriteLine($"Время = {TimeWork.OrganizationQueue(test.librariesString, newElem.ToString())}");
            Console.WriteLine();
            Console.WriteLine("Время поиска первого ключа в коллекции Sorteddictionary<Organization, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryOrgLib, firstElem.BaseOrganization)}");
            Console.WriteLine("Время поиска среднего ключа в коллекции Sorteddictionary<Organization, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryOrgLib, centerElem.BaseOrganization)}");
            Console.WriteLine("Время поиска последнего ключа в коллекции Sorteddictionary<Organization, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryOrgLib, lastElem.BaseOrganization)}");
            Console.WriteLine("Время поиска ключа, не входящего в коллекцию Sorteddictionary<Organization, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryOrgLib, newElem.BaseOrganization)}");
            Console.WriteLine();
            Console.WriteLine("Среднее время поиска первого ключа в коллекции Sorteddictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryStringLib, firstElem.ToString())}");
            Console.WriteLine("Среднее время поиска среднего ключа в коллекции Sorteddictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryStringLib, centerElem.ToString())}");
            Console.WriteLine("Среднее время поиска последнего ключа в коллекции Sorteddictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryStringLib, lastElem.ToString())}");
            Console.WriteLine("Время поиска ключа, не входящего в коллекцию Sorteddictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgKey(test.dictionaryStringLib, newElem.ToString())}");
            Console.WriteLine();
            Console.WriteLine("Среднее время поиска первого элемента в коллекции Sorteddictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgValue(test.dictionaryStringLib, firstElem)}");
            Console.WriteLine("Среднее время поиска среднего элемента в коллекции SortedDictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgValue(test.dictionaryStringLib, centerElem)}");
            Console.WriteLine("Среднее время поиска последнего элемента в коллекции Sorteddictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgValue(test.dictionaryStringLib, lastElem)}");
            Console.WriteLine("Время поиска элемента, не входящего в коллекцию Sorteddictionary<string, Library>");
            Console.WriteLine($"Время = {TimeWork.DictionaryOrgValue(test.dictionaryStringLib, newElem)}");
        }

        static void AddElement(TestCollections test)
        {
            var library = new Library();
            library.Init();
            test.Add(library);
        }

        static void DeleteElement(TestCollections test)
        {
            var library = new Library();
            library.Init();
            test.Delete(library);
        }

        static void DisplayElement(TestCollections test)
        {
            if (test.libraries.Count == 0)
                Console.WriteLine("Коллекции пустые!");
            else
            {
                foreach(var elem in test.libraries)
                {
                    Console.WriteLine(elem + "\n");
                }
            }
        }


        static void Main()
        {
            int action;
            var test = new TestCollections(100);
            string[] menu =
            {
                "1. Вывести время поиска коллекций",
                "2. Добавление элемента",
                "3. Удаление элемента",
                "4. Вывод элементов коллекций",
                "0. Выход из программы"
            };
            do
            {
                foreach (var row in menu)
                    Console.WriteLine(row);
                action = Menu.InputInt("Введите действие");
                switch (action)
                {
                    case 1:
                        DisplayCollectionTime(test);
                        break;
                    case 2:
                        AddElement(test);
                        break;
                    case 3:
                        DeleteElement(test);
                        break;
                    case 4:
                        DisplayElement(test);
                        break;
                    case 0:
                        break;

                }
            }
            while (action != 0);
        }
    }
}
