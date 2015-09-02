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
        private Dictionary<int, Dictionary<K, V>> storage;
        private int count;

        // constructor
        public HashTable()
        {
            storage = new Dictionary<int, Dictionary<K, V>>();
            count = 0;
        }

        // properties
        public V this[K key]
        {
            set
            {
                int hashCode = key.GetHashCode();

                if (!storage.ContainsKey(hashCode))
                    storage[hashCode] = new Dictionary<K, V>();

                if (storage[hashCode].ContainsKey(key))
                    storage[hashCode][key] = value;
                else
                {
                    storage[hashCode].Add(key, value);
                    ++count;
                }
            }

            get
            {
                int hashCode = key.GetHashCode();

                if (storage.ContainsKey(hashCode) && storage[hashCode].ContainsKey(key))
                    return storage[hashCode][key];
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
            foreach(var dict_1 in storage)
            {
                foreach(var dict_2 in dict_1.Value)
                {
                    Console.WriteLine(dict_2.Key + " -> " + dict_2.Value);
                }
            }
        }

        public void remove(K key)
        {
            int hashCode = key.GetHashCode();

            if(storage.ContainsKey(hashCode) && storage[hashCode].ContainsKey(key))
            {
                storage[hashCode].Remove(key);
                --count;
            }
            else
                throw new ArgumentNullException("In HashTable, remove: there's not the key in hash table!");
        }
    }
}
