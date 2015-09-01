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
        private Dictionary<string, string>[] dictionaries;
        private readonly int sizeOfArray;
 
        // constructor
        public HashTable(int size)
        {
            sizeOfArray = size;
            dictionaries = new Dictionary<string, string>[size];

            for(int i = 0; i < sizeOfArray; ++i)
            {
                dictionaries[i] = new Dictionary<string, string>();
            }
        }

        //property
        public string this[string index_string]
        {
            set
            {
                int hashCode = index_string.GetHashCode();
                int index_array = Math.Abs(hashCode % sizeOfArray);

                dictionaries[index_array].Add(index_string, value);
            }

            get
            {
                int hashCode = index_string.GetHashCode();
                int index_array = hashCode % sizeOfArray;

                if(dictionaries[index_array].ContainsKey(index_string))
                {
                    return dictionaries[index_array][index_string];
                }
                throw new IndexOutOfRangeException("In get of property!");
            }
        }
    }
}
