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
        private List<StringPosInFile> positions;
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

            if (startOfString < file.Position)
            {
                positions.Add(new StringPosInFile(startOfString, (int)file.Length));
            }

            file.Close();
        }

        // non-static methods
        public void ShowAll()
        {
            FileStream file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            byte[] buffer;

            foreach (var str in positions)
            {
                file.Seek(str.begin, SeekOrigin.Begin);
                buffer = new byte[str.end - str.begin];
                file.Read(buffer, 0, buffer.Length);
                Console.WriteLine(Encoding.UTF8.GetString(buffer));
            }

            file.Close();
        }

        public List<string> GetNames(string name)
        {
            if (namesSorted == false)
            {
                sortedNames = new int[positions.Count];

                for (int i = 0; i < sortedNames.Length; ++i)
                {
                    sortedNames[i] = i;
                }

                Comparison<int> sortByName = delegate(int a, int b)
                {
                    Record person1 = new Record(path, positions[a]);
                    Record person2 = new Record(path, positions[b]);
                    return person1.name.CompareTo(person2.name);
                };

                //Array.Sort(sortedNames, new ComparerForSorting(path, positions, ComparingValues.name));
                Array.Sort(sortedNames, sortByName);
                namesSorted = true;
            }

            List<string> result = new List<string>();
            int index = Array.BinarySearch(sortedNames, name, new ComparerForBinarySearch(path, positions, ComparingValues.name));

            //if there's required name(s) in file, get them all
            if (index >= 0)
            {
                Record recordBuffer;

                while (index > 0)
                {
                    recordBuffer = new Record(path, positions[sortedNames[index - 1]]);
                    if (recordBuffer.name != name)
                    {
                        break;
                    }
                    --index;
                }

                while (index < sortedNames.Length)
                {
                    recordBuffer = new Record(path, positions[sortedNames[index]]);

                    if (recordBuffer.name != name)
                    {
                        break;
                    }
                    else
                    {
                        result.Add((string)recordBuffer);
                        ++index;
                    }
                }
            }

            return result;
        }

        public List<string> GetSurnames(string surname)
        {
            if (surnamesSorted == false)
            {
                sortedSurnames = new int[positions.Count];

                for (int i = 0; i < sortedSurnames.Length; ++i)
                {
                    sortedSurnames[i] = i;
                }

                //Array.Sort(sortedSurnames, new ComparerForSorting(path, positions, ComparingValues.surname));

                Array.Sort(sortedSurnames, (a, b) => 
                {
                    Record person1 = new Record(path, positions[a]);
                    Record person2 = new Record(path, positions[b]);
                    return person1.surname.CompareTo(person2.surname);
                });

                surnamesSorted = true;
            }

            List<string> result = new List<string>();
            int index = Array.BinarySearch(sortedSurnames, surname, new ComparerForBinarySearch(path, positions, ComparingValues.surname));

            //if there's required name(s) in file, get them all
            if (index >= 0)
            {
                Record recordBuffer;

                while (index > 0)
                {
                    recordBuffer = new Record(path, positions[sortedSurnames[index - 1]]);
                    if (recordBuffer.surname != surname)
                    {
                        break;
                    }
                    --index;
                }

                while (index < sortedSurnames.Length)
                {
                    recordBuffer = new Record(path, positions[sortedSurnames[index]]);

                    if (recordBuffer.surname != surname)
                    {
                        break;
                    }
                    else
                    {
                        result.Add((string)recordBuffer);
                        ++index;
                    }
                }
            }

            return result;
        }

        public List<string> GetIDs(string id)
        {
            if (IDsSorted == false)
            {
                sortedIDs = new int[positions.Count];

                for (int i = 0; i < sortedIDs.Length; ++i)
                {
                    sortedIDs[i] = i;
                }

                //Array.Sort(sortedIDs, new ComparerForSorting(path, positions, ComparingValues.id));
                Array.Sort(sortedIDs, (a, b) =>
                    {
                        Record person1 = new Record(path, positions[a]);
                        Record person2 = new Record(path, positions[a]);
                        return person1.id.CompareTo(person2.id);
                    });

                IDsSorted = true;
            }

            List<string> result = new List<string>();
            int index = Array.BinarySearch(sortedIDs, id, new ComparerForBinarySearch(path, positions, ComparingValues.id));

            //if there's required name(s) in file, get them all
            if (index >= 0)
            {
                Record recordBuffer;

                while (index > 0)
                {
                    recordBuffer = new Record(path, positions[sortedIDs[index - 1]]);
                    if (recordBuffer.id != id)
                    {
                        break;
                    }
                    --index;
                }

                while (index < sortedIDs.Length)
                {
                    recordBuffer = new Record(path, positions[sortedIDs[index]]);

                    if (recordBuffer.id != id)
                    {
                        break;
                    }
                    else
                    {
                        result.Add((string)recordBuffer);
                        ++index;
                    }
                }
            }

            return result;
        }
    }
}
