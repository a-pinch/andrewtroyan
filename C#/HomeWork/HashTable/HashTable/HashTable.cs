using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTable
{
    class HashTable
    {
        // non-static fields
        private Dictionary<int, Dictionary<string, string>> storage;
        private int count;

        // constructor
        public HashTable(int size)
        {
            storage = new Dictionary<int, Dictionary<string, string>>();
            count = 0;
        }

        // properties
        public string this[string index_string]
        {
            set
            {
                int hashCode = index_string.GetHashCode();

                if (!storage.ContainsKey(hashCode))
                    storage[hashCode] = new Dictionary<string, string>();

                if (storage[hashCode].ContainsKey(index_string))
                    storage[hashCode][index_string] = value;
                else
                {
                    storage[hashCode].Add(index_string, value);
                    ++count;
                }
            }

            get
            {
                int hashCode = index_string.GetHashCode();

                if (storage.ContainsKey(hashCode) && storage[hashCode].ContainsKey(index_string))
                    return storage[hashCode][index_string];
                throw new IndexOutOfRangeException("In get of property!");
            }
        }

        public int Count
        {
            get
            {
                return count; 
            }
        }

        // non-static method
        public void printOut()
        {
            foreach(var dict_1 in storage)
            {
                foreach(var dict_2 in dict_1.Value)
                {
                    Console.WriteLine(dict_2.Key + " -> " + dict_2.Value);
                }
            }
        }

        public void remove(string key)
        {
            int hashCode = key.GetHashCode();

            if(storage.ContainsKey(hashCode) && storage[hashCode].ContainsKey(key))
            {
                storage[hashCode].Remove(key);
                --count;
            }
        }
    }
}
