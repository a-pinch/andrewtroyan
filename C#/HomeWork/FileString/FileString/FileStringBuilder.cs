using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileString
{
    class FileStringBuilder // assure that your file is in UTF-16 coding!!!
    {
        // static fields 
        private static readonly int BUF_SIZE = 0x2000;
        private static readonly byte END_OF_FILE = 0xff;
   
        // non-static fields
        public readonly string path;
        private List<int> stringPositions;
        private byte[] buffer;
        private bool isFileRead;

        // constructor
        public FileStringBuilder(string path_)
        {
            path = path_;
            stringPositions = new List<int>() { 2 };
            buffer = new byte[BUF_SIZE];
            isFileRead = false;
        }

        // non-static methods
        public string getString(int index)
        {
            if (index < 0 || (isFileRead == true && index >= stringPositions.Count - 1))
            {
                throw new IndexOutOfRangeException();
            }
            else if (index + 1 < stringPositions.Count)
            {
                return getStringFromTable(index);
            }
            else
            {
                FileStream file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
                file.Seek(stringPositions[stringPositions.Count - 1], SeekOrigin.Begin);

                while (index + 1 >= stringPositions.Count && isFileRead == false)
                {
                    int currentPosition = (int)file.Position;
                    Array.Clear(buffer, 0, buffer.Length);

                    if(file.Read(buffer, 0, BUF_SIZE) < BUF_SIZE) // if we reached end of file
                    {
                        isFileRead = true;
                        buffer[file.Position - currentPosition] = END_OF_FILE;
                    }

                    for (int i = 0; i < buffer.Length; ++i)
                    {
                        if (i + 1 < buffer.Length && i % 2 == 0 && buffer[i] == 0x000a && buffer[i + 1] == 0x0000) // if we reached '\n' symbol
                        {
                            stringPositions.Add(currentPosition + i + 2);
                        }
                        else if (buffer[i] == END_OF_FILE)
                        {
                            stringPositions.Add(currentPosition + i);
                            break;
                        }
                    }
                }

                file.Close();

                if (index + 1 >= stringPositions.Count)
                {
                    throw new IndexOutOfRangeException();
                }
                else
                {
                    return getStringFromTable(index);
                }
            }
        }

        private string getStringFromTable(int index)
        {
            FileStream file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            file.Seek(stringPositions[index], SeekOrigin.Begin);
            byte[] readBytes = new byte[stringPositions[index + 1] - stringPositions[index]];
            file.Read(readBytes, 0, readBytes.Length);
            file.Close();
            string resulting_string = Encoding.Unicode.GetString(readBytes);

            if (resulting_string[resulting_string.Length - 2] == '\r' && resulting_string[resulting_string.Length - 1] == '\n')
            {
                resulting_string = resulting_string.Remove(resulting_string.Length - 2, 2);
            }

            return resulting_string;
        }
    }
}
