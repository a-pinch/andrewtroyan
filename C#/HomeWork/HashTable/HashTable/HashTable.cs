using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HashTable
{
    class HashTable <K, V>
    {
        // non-static fields
        private Dictionary<K, V>[] storage; 
        private int sizeOfArray, count;

        // constructor
        public HashTable(int supposedAmountOfElements)
        {
            sizeOfArray = 3 * supposedAmountOfElements;
            count = 0;
            storage = new Dictionary<K, V>[sizeOfArray];
        }

        // properties
        public V this[K key]
        {
            set
            {
                int hashCode = key.GetHashCode();
                int index = Math.Abs(hashCode) % sizeOfArray;

                if (storage[index] == null)
                    storage[index] = new Dictionary<K, V>();

                if (storage[index].ContainsKey(key))
                    storage[index][key] = value;
                else
                {
                    storage[index].Add(key, value);
                    ++count;
                }
            }

            get
            {
                int hashCode = key.GetHashCode();
                int index = Math.Abs(hashCode) % sizeOfArray;

                if (storage[index] != null && storage[index].ContainsKey(key))
                    return storage[index][key];
                throw new IndexOutOfRangeException("In HashTable, get: there's not the key in hash table!");
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
            foreach(var dict in storage)
            {
                if (dict != null)
                {
                    foreach (var node in dict)
                    {
                        Console.WriteLine(node.Key + " -> " + node.Value);
                    }
                }
            }
        }

        public void remove(K key)
        {
            int hashCode = key.GetHashCode();
            int index = Math.Abs(hashCode) % sizeOfArray;

            if (storage[index] != null && storage[index].ContainsKey(key))
            {
                storage[index].Remove(key);
                --count;
            }
            else
                throw new ArgumentNullException("In HashTable, remove: there's not the key in hash table!");
        }
    }
}
