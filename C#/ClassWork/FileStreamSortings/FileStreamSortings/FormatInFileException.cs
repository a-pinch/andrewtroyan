using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileStreamSortings
{
    class FormatInFileException : FormatException
    {
        // non-static fields

        public FileStream fileWithWrongRecord;

        // constructor

        public FormatInFileException(string message, FileStream file) : base(message)
        {
            fileWithWrongRecord = file;
        }
    }
}
