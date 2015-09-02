using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Generics
{
    
    class Vector2D <T> where T: IComparable
    {
        // non-static fields
        public T[] storage;

        // constructor
        public Vector2D(T[] storage_)
        {
            storage = new T[storage_.Length];
            storage_.CopyTo(storage, 0);
        }

        // non-static methods
        public Vector2D<T> bubbleSort()
        {
            T[] to_return = new T[storage.Length];
            storage.CopyTo(to_return, 0);

            for (int i = 0; i < to_return.Length - 1; ++i)
            {
                for (int j = 0; j < to_return.Length - 1 - i; ++j)
                {
                    if (to_return[j].CompareTo(to_return[j + 1]) > 0)
                    {
                        T max = to_return[j];
                        to_return[j] = to_return[j + 1];
                        to_return[j + 1] = max;
                    }
                }
            }

            return new Vector2D<T>(to_return);
        }

        public Vector2D<T> quickSort()
        {
            T[] to_return = new T[storage.Length];
            storage.CopyTo(to_return, 0);

            quickSortInternal(to_return, 0, to_return.Length - 1);

            return new Vector2D<T>(to_return);
        }

        public void print()
        {
            foreach(var element in storage)
            {
                Console.Write(element + " ");
            }
            Console.WriteLine();
        }

        // static methods
        private static void quickSortInternal(T[] array, int from, int to)
        {
            if(from < to)
            {
                int indexOfMedian = new Random().Next(from, to);
                T temporaryElement = array[indexOfMedian];
                array[indexOfMedian] = array[to];
                array[to] = temporaryElement;

                int i = from;

                while (array[i].CompareTo(array[to]) < 0)
                {
                    ++i;
                }

                for(int j = i; j < to; ++j)
                {
                    if(array[j].CompareTo(array[to]) < 0)
                    {
                        T temporary = array[j];
                        array[j] = array[i];
                        array[i] = temporary;
                        ++i;
                    }
                }

                T temporary_2 = array[i];
                array[i] = array[to];
                array[to] = temporary_2;
                quickSortInternal(array, from, i - 1);
                quickSortInternal(array, i + 1, to);
            }
        }
    }
}
