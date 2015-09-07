using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileStreamSortings
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                FileStreamBuilding test = new FileStreamBuilding("..\\..\\test.txt");
                test.ShowAll();
                Console.WriteLine();

                List<string> names = test.GetNames("Ирина");
                foreach (var name in names)
                {
                    Console.WriteLine(name);
                }
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
            finally
            {
                Console.ReadKey();
            }
        }
    }
}
