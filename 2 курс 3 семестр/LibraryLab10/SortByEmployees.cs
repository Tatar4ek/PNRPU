using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibraryLab10
{
    public class SortByEmployees : IComparer<Organization>
    { 
        public int Compare(Organization? obj1, Organization? obj2)
        {
            if (obj1.Employees > obj2.Employees) return 1;
            if (obj1.Employees < obj2.Employees) return -1;
            else return 0;
        }
    }
}               
