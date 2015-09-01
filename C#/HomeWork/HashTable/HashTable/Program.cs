using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTable
{
    class Program
    {
        static void Main(string[] args)
        {
            HashTable test = new HashTable(100);

            test["9:00"] = "Studying";
            test["12:00"] = "Going home";
            test["13:00"] = "Programming";

            test.remove("12:00");

            test.printOut();
            Console.WriteLine("Total amount of elements: " + test.Count);
            Console.ReadKey();
        }
    }
}
