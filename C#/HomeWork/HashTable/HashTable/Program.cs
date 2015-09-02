using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTable
{
    class Program
    {
        static void Main(string[] args)
        {
            HashTable<string, string> first_hash_table = new HashTable<string, string>(3);

            first_hash_table["9:00"] = "Studying";
            first_hash_table["12:00"] = "Going home";
            first_hash_table["13:00"] = "Programming";

            first_hash_table.remove("12:00");
            first_hash_table.printOut();
            Console.WriteLine("Total amount of first hash table's elements: " + first_hash_table.Count + "\n");

            HashTable<int, string> second_hash_table = new HashTable<int, string>(3);

            second_hash_table[1] = "One";
            second_hash_table[2] = "Two";
            second_hash_table[3] = "Three";

            second_hash_table.printOut();
            Console.WriteLine("Total amount of second hash table's elements: " + second_hash_table.Count);

            Console.ReadKey();
        }
    }
}
