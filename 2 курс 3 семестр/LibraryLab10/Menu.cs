using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LibraryLab10
{
    public class Menu
    {
        public static int InputInt(string message)
        {
            int input;
            Console.WriteLine(message);
            while (!int.TryParse(Console.ReadLine(), out input))
            {
                Console.WriteLine("Введено не число");
                Console.WriteLine(message);
            }
            return input;
        }
    }
}
