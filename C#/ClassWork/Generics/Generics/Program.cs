using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generics
{
    class Program
    {
        static void Main(string[] args)
        {
            Vector2D<int> test = new Vector2D<int>(new int[8] { 6, 0, 190, 31, 5, 2, 5, 621 });
            Vector2D<int> test2 = test.quickSort();

            test.print();
            test2.print();
            Console.ReadKey();
        }
    }
}
