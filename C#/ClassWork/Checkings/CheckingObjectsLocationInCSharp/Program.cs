using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace CheckingObjectsLocationInCSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            var before = DateTime.Now;

            LinkedList<Pupil> list = new LinkedList<Pupil>();
            int amount = 1000000;

            for (int i = 0; i < amount; ++i)
            {
                list.AddLast(new Pupil());
            }

            for (int i = 0; i < amount / 10; ++i)
            {
                list.RemoveLast();
            }

            for (int i = 0; i < amount / 10; ++i)
            {
                list.AddFirst(new Pupil());
            }

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
