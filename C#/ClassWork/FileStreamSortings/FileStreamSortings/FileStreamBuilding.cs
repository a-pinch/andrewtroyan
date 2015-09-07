using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileStreamSortings
{
    class FileStreamBuilding
    {
        // static fields

        private static readonly int BUF_SIZE = 0x2000;

        // non-static fields

        public readonly string path;
        public List<StringPosInFile> positions;
        private int[] sortedNames, sortedSurnames, sortedIDs;
        private byte[] buffer;
        bool namesSorted, surnamesSorted, IDsSorted;

        // constructor

        public FileStreamBuilding(string path_)
        {
            path = path_;

            if (File.Exists(path) == false)
            {
                throw new InvalidDataException("In FileStreamBuilding(): file doesn't exists.");
            }

            positions = new List<StringPosInFile>();
            buffer = new byte[BUF_SIZE];

            FileStream file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            file.Seek(3, SeekOrigin.Begin); // passing by BOM

            int startOfString = (int)file.Position, endOfString;
            int currentFilePos;
            int readBytes;

            while (file.Position != file.Length)
            {
                currentFilePos = (int)file.Position;
                Array.Clear(buffer, 0, BUF_SIZE);
                readBytes = file.Read(buffer, 0, BUF_SIZE);

                for (int i = 0; i < readBytes; ++i)
                {
                    if (buffer[i] == 0x000d) // if it's '\r'
                    {
                        endOfString = currentFilePos + i;
                        positions.Add(new StringPosInFile(startOfString, endOfString));
                    }
                    else if (buffer[i] == 0x000a) // if it's '\n'
                    {
                        startOfString = currentFilePos + i + 1;
                    }
                }
            }

            if (startOfString + 1 < file.Position)
            {
                positions.Add(new StringPosInFile(startOfString, (int)file.Length));
            }

            file.Close();
        }

        // non-static methods
        public List<string> getNames(string name)
        {
            if (namesSorted == false)
            {
                sortedNames = new int[positions.Count];

                for (int i = 0; i < sortedNames.Length; ++i)
                {
                    sortedNames[i] = i;
                }

                Array.Sort(sortedNames, new NamesComparer(path, positions, ComparingValues.name));
            }

            // execute binary search

            return new List<string>();
        }
    }
}
