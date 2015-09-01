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

            test["Andrew"] = "Troyan";

            Console.WriteLine(test["Andrew"]);
            Console.ReadKey();
        }
    }
}
