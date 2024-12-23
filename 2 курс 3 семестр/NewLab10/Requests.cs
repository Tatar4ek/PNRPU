using LibraryLab10;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NewLab10
{
    public class Requests
    {
        //Количество работников в заданной организации
        public static void EmployeesCount(Organization[] organizations, string name)
        {
            bool isFound = false;
            foreach (var organization in organizations)
            {
                if (organization.Name == name)
                {
                    Console.WriteLine($"Количество работников в организации {organization.Name}: {organization.Employees}");
                    isFound = true;
                    break;
                }
            }
            if (!isFound)
                Console.WriteLine("Данной организации в массиве нет!");
        }

        //Количество библиотек в городе
        public static int LibraryCount(Organization[] organizations)
        {
            int count = 0;
            foreach (var org in organizations)
            {
                if (org is Library)
                    count++;
            }
            return count;
        }

        //Количество книг во всех библиотеках
        public static int BooksCount(Organization[] organizations)
        {
            int count = 0;
            var labrires = new List<Library>();
            foreach (var organization in organizations)
            {
                if (organization is Library)
                {
                    labrires.Add(organization as Library);
                }
            }
            foreach(var library in labrires)
            {
                count += library.Books;
            }
            return count;
        }
    }
}
