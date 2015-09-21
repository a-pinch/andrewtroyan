using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Text.RegularExpressions;

namespace FileTree
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"D:\andrewtroyan\C#";

            FileWorking.ShowDirectories(path);

            Console.ReadKey();
        }
    }
}
