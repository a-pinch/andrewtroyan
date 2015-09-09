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

                List<Record> records = test.GetRecordsByName("Ирина");
                foreach (var record in records)
                {
                    Console.WriteLine((string)record);
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
