using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileStreamSortings
{
    // provides storage of data bases and methods that retrieve records from data base with given arguments (name, surname or id)
    class FileStreamBuilding
    {
        // static fields

        private const int BUF_SIZE = 0x2000;

        // non-static fields

        public readonly string path;
        private List<StringPosInFile> positions;
        private int[] sortedNames, sortedSurnames, sortedIDs;
        private bool isNamesSorted, isSurnamesSorted, isIDsSorted;
        KeyGeneration GenerateKey;

        // constructor

        public FileStreamBuilding(string path_)
        {     
            byte[] buffer;

            path = path_;
            if (File.Exists(path) == false)
            {
                throw new InvalidDataException("In FileStreamBuilding(): file doesn't exist.");
            }

            positions = new List<StringPosInFile>();
            buffer = new byte[BUF_SIZE];

            FileStream file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite);
            file.Seek(3, SeekOrigin.Begin); // passing by BOM

            int startOfString = (int)file.Position, endOfString;
            int currentFilePos;
            int readBytes;

            // while end of file is not reached
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

            // warning! last string in file with no '\r\n' remained!
            if (startOfString < file.Position)
            {
                positions.Add(new StringPosInFile(startOfString, (int)file.Length));
            }

            file.Close();

            SetDelegates();
        }

        // non-static methods

        private void SetDelegates()
        {
            GenerateKey = delegate(ComparingValues valuesToCompare)
            {
                int[] valuesToSort;

                valuesToSort = new int[positions.Count];

                for (int i = 0; i < valuesToSort.Length; ++i)
                {
                    valuesToSort[i] = i;
                }

                Comparison<int> sortByValue = delegate(int a, int b)
                {
                    Record person1 = new Record(path, positions[a]);
                    Record person2 = new Record(path, positions[b]);

                    if (valuesToCompare == ComparingValues.name)
                    {
                        return person1.name.CompareTo(person2.name);
                    }
                    else if (valuesToCompare == ComparingValues.surname)
                    {
                        return person1.surname.CompareTo(person2.surname);
                    }
                    else
                        return person1.id.CompareTo(person2.id);
                };

                Array.Sort(valuesToSort, sortByValue);

                if (valuesToCompare == ComparingValues.name)
                {
                    sortedNames = valuesToSort;
                }
                else if (valuesToCompare == ComparingValues.surname)
                {
                    sortedSurnames = valuesToSort;
                }
                else
                    sortedIDs = valuesToSort;
            };
        }

        // print all data base item to console
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

        // get records with given first name
        public List<Record> GetRecordsByName(string name)
        {
            if (isNamesSorted == false)
            {
                GenerateKey(ComparingValues.name);
                isNamesSorted = true;
            }

            List<Record> result = new List<Record>();
            int index = Array.BinarySearch(sortedNames, name, new ComparerForBinarySearch(path, positions, ComparingValues.name));

            // if there's required name(s) in file, get them all
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
                        result.Add(recordBuffer);
                        ++index;
                    }
                }
            }

            return result;
        }

        // get records with given surname
        public List<Record> GetRecordsBySurname(string surname)
        {
            if (isSurnamesSorted == false)
            {
                GenerateKey(ComparingValues.surname);
                isSurnamesSorted = true;
            }

            List<Record> result = new List<Record>();
            int index = Array.BinarySearch(sortedSurnames, surname, new ComparerForBinarySearch(path, positions, ComparingValues.surname));

            // if there's required name(s) in file, get them all
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
                        result.Add(recordBuffer);
                        ++index;
                    }
                }
            }

            return result;
        }

        // get record(s) with given id
        public List<Record> GetRecordsByID(string id)
        {
            if (isIDsSorted == false)
            {
                GenerateKey(ComparingValues.id);
                isIDsSorted = true;
            }

            List<Record> result = new List<Record>();
            int index = Array.BinarySearch(sortedIDs, id, new ComparerForBinarySearch(path, positions, ComparingValues.id));

            // if there's required name(s) in file, get them all
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
                        result.Add(recordBuffer);
                        ++index;
                    }
                }
            }

            return result;
        }
    }
}
