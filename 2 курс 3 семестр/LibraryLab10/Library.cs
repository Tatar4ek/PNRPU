using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibraryLab10
{
    public class Library : Organization
    {
        private int books;

        public int Books
        {
            set
            {
                if (value < 0)
                    throw new Exception("В библиотеке не может быть книг меньше нуля!");
                else
                    books = value;
            }
            get { return books; }
        }

        public Organization BaseOrganization
        {
            get
            {
                return new Organization(Name, Address, Employees);
            }
        }

        public Library(string? name, string? address, int employees, int books) : base(name,address,employees)
        {
            Books = books;
        }

        public Library() : base() 
        { 
            Books = 0; 
        }

        public Library(Library other) : base(other)
        {
            Books = other.Books;
        }

        public override void Show()
        {
            Console.WriteLine(ToString());
        }

        public new void OrgShow()
        {
            Console.WriteLine($"Название организации: {Name}\nАдрес организации:{Address}\nКоличество сотрудников:{Employees}\nКоличество книг в библиотеке:{Books}");
        }

        public override void Init()
        {
            base.Init();
            Books = Menu.InputInt("Введите количество книг в библиотеке");
        }

        public override void RandomInit()
        {
            var rnd = new Random();
            base.RandomInit();
            Books = rnd.Next(1,10000);
        }

        public override bool Equals(object? obj)
        {
            if (obj is Library other)
            {
                return Name == other.Name && Address == other.Address && Employees == other.Employees && Books == other.Books;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Name,Address,Employees,Books);
        }

        public override string ToString()
        {
            return base.ToString() + $"\nКоличество книг в библиотеке:{Books}"; 
        }

        public override object Clone()
        {
            return new Library(this.Name, this.Address, this.Employees, this.Books);
        }

        public override object ShallowCopy()
        {
            return (Library)this.MemberwiseClone();
        }


    }
}
