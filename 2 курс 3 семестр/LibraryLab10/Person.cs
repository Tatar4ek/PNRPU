using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;

namespace LibraryLab10
{
    public class Person : IInit
    {
        string? name;
        int age;

        public string[] names = { "Антон", "Егор", "Григорий" };

        public int Age
        {
            set
            {
                if (value < 0)
                    throw new Exception("Возраст не может быть меньше нуля!");
                else
                    age = value;
            }
            get { return age; }
        }

        public string? Name
        {
            get { return name; }
            set { name = value; }
        }

        public Person()
        {
            Name = "";
            Age = 0;
        }

        public Person(string name, int age)
        {
            Name = name;
            Age = age;
        }

        public Person(Person other)
        {
            this.Name = other.Name;
            this.Age = other.Age;
        }

        public void Init()
        {
            Console.WriteLine("Введите имя человека: ");
            Name = Console.ReadLine();
            Age = Menu.InputInt("Введите возраст человека: ");
        }

        public void RandomInit()
        {
            var rnd = new Random();
            Name = names[rnd.Next(0, 3)];
            Age = rnd.Next(0, 100);
        }

        public override string ToString()
        {
            return $"Имя человека: {Name}\nВозраст человека: {Age}";
        }

    }
}
