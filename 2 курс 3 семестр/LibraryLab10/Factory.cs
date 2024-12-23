using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibraryLab10
{
    public class Factory : Organization
    {
        private int details;
        public int Details
        {
            set
            {
                if (value < 0)
                    throw new Exception("Количество деталей не может быть меньше нуля!");
                else
                    details = value;
            }
            get { return details; }
        }

        public Factory(string? name, string? address, int employees, int details) : base(name,address,employees)
        {
            Details = details;
        }

        public Factory() : base()
        {
            Details = 0;
        }

        public Factory(Factory other) : base(other)
        {
            Details = other.Details;
        }

        public override void Show()
        {
            Console.WriteLine(ToString());
        }

        public new void OrgShow()
        {
            Console.WriteLine($"Название организации: {Name}\nАдрес организации:{Address}\nКоличество сотрудников:{Employees}\nКоличество изготовленных деталей:{Details}");
        }

        public override void Init()
        {
            base.Init();
            Details = Menu.InputInt("Введите количество деталей, производимых заводом");
        }

        public override void RandomInit()
        {
            var rnd = new Random();
            base.RandomInit();
            Details = rnd.Next(1, 10000);
        }

        public override bool Equals(object? obj)
        {
            if (obj is Factory other)
            {
                return Name == other.Name && Address == other.Address && Employees == other.Employees && Details == other.Details;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Name, Address, Employees, Details);
        }

        public override string ToString()
        {
            return base.ToString() + $"\nКоличество изготовленный деталей:{Details}";
        }

        public override object Clone()
        {
            return new Factory(this.Name, this.Address, this.Employees, this.details);
        }

        public override object ShallowCopy()
        {
            return (Factory)this.MemberwiseClone();
        }
    }
}
