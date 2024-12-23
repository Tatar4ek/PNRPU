namespace LibraryLab10
{
    public class Organization : IInit, ICloneable, IComparable
    {
        private string? name;
        private string? address;
        private int employees;

        public string? Name
        {
            get { return name; }
            set { name = value; }
        }

        public string? Address
        {
            get { return address; }
            set { address = value; }
        }


        public int Employees
        {
            set
            {
                if (value < 0)
                {
                    throw new Exception("Кол-во сотрудников не может быть меньше нуля");
                }
                else
                    employees = value;
            }
            get { return employees; }
        }

        public Organization(string? name, string? address, int employees)
        {
            Name = name;
            Address = address;
            Employees = employees;
        }

        public Organization()
        {
            Name = "";
            Address = "";
            Employees = 0;
        }

        public Organization(Organization other)
        {
            Name = other.Name;
            Address = other.Address;
            Employees = other.Employees;
        }

        public virtual void Show()
        {
            Console.WriteLine(ToString());
        }

        public void OrgShow()
        {
            Console.WriteLine($"Название организации: {Name}\nАдрес организации: {Address}\nКоличество сотрудников: {Employees}\n");
        }

        public virtual void Init()
        {
            Console.WriteLine("Введите название организации");
            Name = Console.ReadLine();
            Console.WriteLine("Введите адрес организации");
            Address = Console.ReadLine();
            Employees = Menu.InputInt("Введите количество сотрудников");
        }

        public virtual void RandomInit()
        {
            var rnd = new Random();
            Name = "Организация-" + rnd.Next(1,10000);
            Address = "Улица Уличная, дом " + rnd.Next(1, 10000);
            Employees = rnd.Next(1, 10000);
        }

        public override bool Equals(object? obj)
        {
            if (obj is Organization other)
            {
                return Name == other.Name && Address == other.Address && Employees == other.Employees;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Name, Address, Employees);
        }

        public override string ToString()
        {
            return $"Название организации: {Name}\nАдрес организации: {Address}\nКоличество сотрудников: {Employees}";
        }

        public int CompareTo(object? obj)
        {
            if (obj is Organization other)
            {
                if (string.Compare(this.Name, other.Name) > 0)
                    return 1;
                else if (string.Compare(this.Name, other.Name) < 0)
                    return -1;
                return 0;
            }
            else
                throw new Exception("Некорректное сравнение");
        }

        public virtual object Clone()
        { 
            return new Organization(this.Name, this.Address, this.Employees);
        }

        public virtual object ShallowCopy()
        {
            return (Organization)this.MemberwiseClone();
        }
    }
}
