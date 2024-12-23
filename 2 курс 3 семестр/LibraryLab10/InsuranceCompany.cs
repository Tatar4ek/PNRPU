using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibraryLab10
{
    public class InsuranceCompany : Organization
    {
        private int insurancePrice;
        public int InsurancePrice
        {
            set
            {
                if (value < 0)
                {
                    throw new Exception("Цена страховки не может быть меньше нуля");
                }
                else
                    insurancePrice = value;
            }
            get { return insurancePrice; }
        }    

        public InsuranceCompany(string? name, string? address, int employees, int price) : base(name, address, employees)
        {
            insurancePrice = price;
        }

        public InsuranceCompany() : base()
        {
            InsurancePrice = 0;
        }

        public InsuranceCompany(InsuranceCompany other) : base(other)
        {
            InsurancePrice = other.InsurancePrice;
        }

        public override void Show()
        {
            Console.WriteLine(ToString());
        }

        public new void OrgShow()
        {
            Console.WriteLine($"Название организации: {Name}\nАдрес организации:{Address}\nКоличество сотрудников:{Employees}\nЦена страховки:{InsurancePrice}");
        }

        public override void Init()
        {
            base.Init();
            InsurancePrice = Menu.InputInt("Введите цену страховки");
        }

        public override void RandomInit()
        {
            var rnd = new Random();
            base.RandomInit();
            InsurancePrice = rnd.Next(100, 10000);
        }

        public override bool Equals(object? obj)
        {
            if (obj is  InsuranceCompany other)
                return Name == other.Name && Address == other.Address && Employees == other.Employees && InsurancePrice == other.InsurancePrice;
            else 
                return false;
        }

        public override int GetHashCode()
        {
            return HashCode.Combine(Name, Address, Employees,InsurancePrice);
        }

        public override string ToString()
        {
            return base.ToString() + $"\nЦена страховки: {InsurancePrice}";
        }

        public override object Clone()
        {
            return new InsuranceCompany(this.Name, this.Address, this.Employees, this.InsurancePrice);
        }

        public override object ShallowCopy()
        {
            return (InsuranceCompany)this.MemberwiseClone();
        }
    }
}
