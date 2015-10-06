using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Checkings
{
    class WorkWithPrimes
    {
        public static void GeneratePrimes(uint amount, string path)
        {
            using (var file = new StreamWriter(path))
            {
                if (amount > 0)
                {
                    uint count = 0;
                    int currentNumber = 2;

                    file.WriteLine(currentNumber++);
                    ++count;

                    while (count < amount)
                    {
                        if (CheckForPrimality(currentNumber))
                        {
                            file.WriteLine(currentNumber);
                            ++count;
                        }

                        currentNumber += 2;
                    }
                }
            }
        }

        public static bool CheckForPrimality(int number)
        {
             for (int i = 2; i * i <= number; i++)
             {
                 if (number % i == 0)
                 {
                     return false;
                 }
             }
             return true;
        }
    }
}
