using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileStreamSortings
{
    enum ComparingValues
    {
        name,
        surname, 
        id
    }

    class ComparerForSorting : IComparer<int>
    {
        // non-static fields 
        string path;
        List<StringPosInFile> strPositions;
        ComparingValues value;

        // constructor
        public ComparerForSorting(string path_, List<StringPosInFile> strPositions_, ComparingValues value_)
        {
            path = path_;
            strPositions = strPositions_;
            value = value_;
        }

        // non-static methods
        int IComparer<int>.Compare(int first, int second)
        {
            Record firstRecord = new Record(path, strPositions[first]);
            Record secondRecord = new Record(path, strPositions[second]);

            if (value == ComparingValues.name)
            {
                return firstRecord.name.CompareTo(secondRecord.name);
            }
            else if(value == ComparingValues.surname)
            {
                return firstRecord.surname.CompareTo(secondRecord.surname);
            }
            else
            {
                return firstRecord.id.CompareTo(secondRecord.id);
            }
        }
    }

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
