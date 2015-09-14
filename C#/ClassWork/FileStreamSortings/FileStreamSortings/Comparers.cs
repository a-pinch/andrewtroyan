using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileStreamSortings
{
    // provides logic for binary search
    class ComparerForBinarySearch : IComparer
    {
        // non-static fields 
        string path;
        List<StringPosInFile> strPositions;
        ComparingValues value;

        // constructor
        public ComparerForBinarySearch(string path_, List<StringPosInFile> strPositions_, ComparingValues value_)
        {
            path = path_;
            strPositions = strPositions_;
            value = value_;
        }

        // non-static methods
        int IComparer.Compare(object first, object second)
        {
            if (first is int == false || second is string == false)
            {
                throw new ArgumentException("In ComparerForBinarySearch.Compare(object, object): invalid argument(s)");
            }

            int index = (int)first;
            string valueToCompare = (string)second;

            Record record = new Record(path, strPositions[index]);

            if (value == ComparingValues.name)
            {
                return record.name.CompareTo(valueToCompare);
            }
            else if (value == ComparingValues.surname)
            {
                return record.surname.CompareTo(valueToCompare);
            }
            else
            {
                return record.id.CompareTo(valueToCompare);
            }
        }
    }
}
