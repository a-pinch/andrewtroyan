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
                FileStreamBuilding test = new FileStreamBuilding("..\\..\\test1.txt");

                FileStream file = new FileStream("..\\..\\test1.txt", FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                foreach (var str in test.positions)
                {
                    file.Seek(str.begin, SeekOrigin.Begin);
                    byte[] buffer = new byte[str.end - str.begin];
                    file.Read(buffer, 0, buffer.Length);
                    Console.WriteLine(Encoding.UTF8.GetString(buffer));
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
