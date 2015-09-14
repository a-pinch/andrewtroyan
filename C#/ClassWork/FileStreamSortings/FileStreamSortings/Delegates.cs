using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileStreamSortings
{
    // delegate for key generation
    delegate void KeyGeneration(ComparingValues valuesToCompare);
    delegate void GetValues(ref List<Record> storage, string valueToCompare, int binarySearchIndex);
}
