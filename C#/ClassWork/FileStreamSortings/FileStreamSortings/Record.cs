using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileStreamSortings
{
    class Record
    {
        // non-static fields

        public readonly string name, surname, id;

        // constructors

        public Record(string info)
        {
            string[] split = info.Split(new Char[] { ' ' });

            name = split[0];
            surname = split[1];
            id = split[2];
        }

        public Record(string filePath, StringPosInFile pos)
        {
            FileStream file = new FileStream(filePath, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            file.Seek(pos.begin, SeekOrigin.Begin);
            byte[] buffer = new byte[pos.end - pos.begin];
            file.Read(buffer, 0, buffer.Length);
            string info = Encoding.UTF8.GetString(buffer);

            string[] split = info.Split(new Char[] { ' ' });

            name = split[0];
            surname = split[1];
            id = split[2];
        }
    }
}
