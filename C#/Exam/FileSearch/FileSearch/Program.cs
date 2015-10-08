using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileSearch
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                WorkWithFile file = new WorkWithFile("..\\..\\text.txt");

                foreach (var word in file.GetMostOccurredWord(60))
                {
                    Console.WriteLine(word);
                }
            }
            catch (FileNotFoundException x)
            {
                Console.WriteLine(x.Message);
            }
            finally
            {
                Console.ReadKey();
            }
        }
    }
}
