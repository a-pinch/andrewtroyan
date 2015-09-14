using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FileStreamSortings
{
    // contains beginning position and (last position + 1) of record
    public struct StringPosInFile
    {
        public readonly int begin, end;

        public StringPosInFile(int begin_, int end_) 
        {
            begin = begin_; end = end_; 
        }
    }
}
