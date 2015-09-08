using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Delegates
{
    delegate bool isOdd(int x);

    class Program
    {
        delegate int FirstDelegate(int num);
        delegate int SecondDelegate(int first, int second);
        delegate int ReduceDelegate(params int[] array);

        static int[] map(int[] array, FirstDelegate userDelegate)
        {
            int[] result = new int[array.Length];

            for (int i = 0; i < array.Length; ++i )
            {
                result[i] = userDelegate(array[i]);
            }

            return result;
        }

        static int Reduce(int[] arr, int acc_init, SecondDelegate del)
        {
            var acc = acc_init;
            foreach(var x in arr)
            {
                acc = del(acc, x);
            }
            return acc;
        }

        static void Main(string[] args)
        {
            var numbers = new int[10];
            Random rand = new Random();

            for (int i = 0; i < numbers.Length; ++i )
            {
                numbers[i] = rand.Next(100);
            }

            FirstDelegate sqrtUser = delegate(int x)
            {
                return x * x;
            };

            int[] result = map(numbers, sqrtUser);
            int[] result2 = map(numbers, x => x * x);

            map(numbers, x => { Console.WriteLine(x); return x; });

            Console.WriteLine();

            map(result, x => { Console.WriteLine(x); return x; });

            Console.WriteLine();

            ReduceDelegate sum = array => {
                int sum_res = 0;
                foreach (int num in array)
                {
                    sum_res += num;
                }
                return sum_res;
            };

            int result_sum = sum(new int[3] { 1, 2, 3 });
            Console.WriteLine(result_sum);

            int[] array_test =new int[] {2, 3, 4, 2, 1, 4, 5, 2, 2, -0, 483};
            Console.WriteLine(Reduce(array_test, 0, (acc, x) => acc += x));

            Console.ReadKey();
        }
    }
}
