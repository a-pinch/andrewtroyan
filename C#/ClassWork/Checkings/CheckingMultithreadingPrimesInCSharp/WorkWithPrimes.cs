using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace CheckingMultithreadingPrimesInCSharp
{
    class WorkWithPrimes
    {
        // non-static fields

        private int amountOfPrimesToFind;
        private int writtenPrimes;
        private Queue<int> primes;
        private StreamWriter file;
        private Mutex mutex;

        // constructors

        public WorkWithPrimes(int amountOfPrimesToFind_, string filePath_)
        {
            if (amountOfPrimesToFind_ > 0)
            {
                amountOfPrimesToFind = amountOfPrimesToFind_;
                writtenPrimes = 0;
                primes = new Queue<int>();
                file = new StreamWriter(filePath_);
                mutex = new Mutex();
            }
            else
            {
                throw new ArgumentException("In WorkWithPrimes.WorkWithPrimes(int): argument must be positive.");
            }
        }

        // non-static methods

        public void Start()
        {
            Thread threadForFileWriting = new Thread(new ThreadStart(WriteToFile));
            threadForFileWriting.Start();
            GeneratePrimes();
            threadForFileWriting.Join();
            file.Dispose();
        }

        private void GeneratePrimes()
        {
            int count = 0;
            int currentNumber = 2;
            
            primes.Enqueue(currentNumber++);
            ++count;

            while (count < amountOfPrimesToFind)
            {
                if (CheckForPrimarity(currentNumber))
                {
                    lock (mutex)
                    {
                        primes.Enqueue(currentNumber);
                    }
                    ++count;
                }

                currentNumber += 2;
            }
        }

        private void WriteToFile()
        {
            while (writtenPrimes != amountOfPrimesToFind)
            {
                while (primes.Count != 0)
                {
                    lock (mutex)
                    {
                        file.WriteLine(primes.Dequeue());
                    }
                    ++writtenPrimes;
                }
            }
        }

        //static methods

        private static bool CheckForPrimarity(int number)
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
