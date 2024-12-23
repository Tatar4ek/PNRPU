using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NewLab10
{
    class Employee : ICloneable
    {
        public string Name { get; set; }
        public Company Work { get; set; }
        public Employee(string name, Company company)
        {
            Name = name;
            Work = company;
        }
        public override string ToString()
        {
            return $"Имя сотрудника: {Name}, Компания: {Work.Name}";
        }
        public object Clone()
        {
            return new Employee(Name, new Company(Work.Name));
        }
        public object ShallowCopy()
        {
            return (Employee)this.MemberwiseClone();
        }
    }
    class Company
    {
        public string Name { get; set; }
        public Company(string name) => Name = name;
    }
}
