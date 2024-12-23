using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibraryLab10
{
    public class ShipCompany : Organization
    {
        private int shipCount;
        public int ShipCount
        {
            set
            {
                if (value < 0)
                    throw new Exception("Кораблей меньше нуля быть не может");
                else
                    shipCount = value;
            }
            get { return shipCount; }
        }

        public ShipCompany(string? name, string? address, int employees, int shipCount) : base(name,address,employees)
        {
            ShipCount = shipCount;
        }

        public ShipCompany() : base()
        {
            shipCount = 0;
        }

        public ShipCompany(ShipCompany other) : base(other)
        {
            shipCount = other.ShipCount;
        }

        public override void Show()
        {
            Console.WriteLine(ToString());
        }

        public new void OrgShow()
        {
            Console.WriteLine($"Название организации: {Name}\nАдрес организации:{Address}\nКоличество сотрудников:{Employees}\nКоличество изготовленных кораблей:{ShipCount}");
        }

        public override void Init()
        {
            base.Init();
            ShipCount = Menu.InputInt("Введите количество кораблей");
        }

        public override void RandomInit()
        {
            var rnd = new Random();
            base.RandomInit();
            ShipCount = rnd.Next(1, 1000);
        }

        public override bool Equals(object? obj)
        {
            if (obj is ShipCompany other)
            {
                return Name == other.Name && Address == other.Address && Employees == other.Employees && ShipCount == other.ShipCount;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Name, Address, Employees, ShipCount);
        }

        public override string ToString()
        {
            return base.ToString() + $"\nКоличество изготовленный кораблей: {shipCount}";
        }

        public override object Clone()
        {
            return new ShipCompany(this.Name, this.Address, this.Employees, this.ShipCount);
        }

        public override object ShallowCopy()
        {
            return (ShipCompany)this.MemberwiseClone();
        }
    }
}
