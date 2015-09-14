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
                string path;
                Console.WriteLine("Type path: ");
                path = Console.ReadLine();

                if (Path.GetExtension(path) != ".txt")
                {
                    throw new FormatException("In Program.Main(): invalid extension. The extension must be \".txt\"");
                }

                FileStreamBuilding test = new FileStreamBuilding(path);

                test.ShowAll();
                Console.WriteLine();

                List<Record> records = test.GetRecordsByName("Ирина");
                foreach (var record in records)
                {
                    Console.WriteLine((string)record);
                }
            }
            catch (FormatInFileException e)
            {
                Console.WriteLine(e.Message);
                e.fileWithWrongRecord.Dispose();
            }
            catch (FormatException e)
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
