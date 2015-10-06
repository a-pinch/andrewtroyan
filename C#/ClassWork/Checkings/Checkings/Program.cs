using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Checkings
{
    class Program
    {
        static void Main(string[] args)
        {
            var before = DateTime.Now;
            WorkWithPrimes.GeneratePrimes(500000, "..\\..\\test.txt");
            var after = DateTime.Now;

            using (var file = new StreamWriter("..\\..\\result.txt"))
            {
                file.WriteLine(after.Subtract(before).TotalSeconds);
            }
        }
    }
}
