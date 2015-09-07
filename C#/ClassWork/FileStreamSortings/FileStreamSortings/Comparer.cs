using System;
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

    class NamesComparer : IComparer<int>
    {
        // non-static fields 
        string path;
        List<StringPosInFile> strPositions;
        ComparingValues value;

        // constructor
        public NamesComparer(string path_, List<StringPosInFile> strPositions_, ComparingValues value_)
        {
            path = path_;
            strPositions = strPositions_;
            value = value_;
        }

        // non-static methods
        public int IComparer<int>.Compare(int first, int second)
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
}
