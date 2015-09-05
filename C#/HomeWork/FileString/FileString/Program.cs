using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileString
{
    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                FileStringBuilder testFile = new FileStringBuilder("..\\..\\test.txt");
                List<string> testStrings = new List<string>();

                for (int i = 0; i < 6; ++i)
                {
                    testStrings.Add(testFile.getString(i));
                }

                foreach (string str in testStrings)
                {
                    Console.WriteLine(str);
                }
            }
            catch (IndexOutOfRangeException e)
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
