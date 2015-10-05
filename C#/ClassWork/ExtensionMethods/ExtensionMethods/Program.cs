using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtensionMethods
{
    class Program
    {
        static void Main(string[] args)
        {
            string a = "hello", b = "bye";
            Console.WriteLine(a.GreaterThan(b));

            int[] array = { 1, 2, 3, 4 };
            Console.WriteLine(array.Implode());
            Console.WriteLine(array.ToJSON());

            List<int> list = new List<int>() { 5, 6, 7, 8 };
            Console.WriteLine(list.Implode());
            Console.WriteLine(list.ToJSON());

            Dictionary<int, string> dict = new Dictionary<int, string>();
            dict.Add(3, "three");
            dict.Add(5, "five");
            Console.WriteLine(dict.ToJSON());

            TestClass test = new TestClass("Andrew", 13);
            Console.WriteLine(test.ToJSON());

            Console.ReadKey();
        }
    }
}
