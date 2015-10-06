using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CheckingMultithreadingPrimesInCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            WorkWithPrimes primesGenerator = new WorkWithPrimes(500000, "..\\..\\test.txt");

            var before = DateTime.Now;
            primesGenerator.Start();
            var after = DateTime.Now;

            var result = after.Subtract(before).TotalMilliseconds;

            using (var file = new StreamWriter("..\\..\\result.txt"))
            {
                file.WriteLine(result);
            }

            Console.WriteLine(result);
            Console.ReadKey();
        }
    }
}
