using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FirstProgram
{
    class Program
    {
        public static void Hello() 
        {
            Console.WriteLine("Hello!");
        }

        static void Main(string[] args)
        {
            //using static method

            Hello();

            // array
            int[] x = new int[5] /* optional */ {1, 2, 3, 4, 5};
            x[4] = 1;

            for (int i = 0; i < x.Length; ++i) 
            {
                Console.WriteLine(x[i]);
            }

            // array of arrays

            int[][] matrix = new int[2][];

            for (int i = 0; i < matrix.Length; ++i)
            {
                matrix[i] = new int[i + 1];
            }

            matrix[1][0] = 1;

            // matrix

            int[,] matrix_2 = new int[2, 2];

            matrix_2[1, 1] = 7;

            // var (like auto in C++)

            var pi = Math.Atan(1) * 4;
            object z = pi;
            double q = (double)z;

            Console.WriteLine(q);

            // wait for user's input for exit

            Vector vector_test1 = new Vector(0, 0, 1), vector_test2 = new Vector(1, 0, 0);
            int scalar_value = Vector.ScalarMultiply(vector_test1, vector_test2);
            Vector vector_test3 = Vector.VectorMultiply(vector_test1, vector_test2);
            Console.WriteLine(scalar_value);
            vector_test3.Print();

            Console.ReadKey();
        }
    }
}
