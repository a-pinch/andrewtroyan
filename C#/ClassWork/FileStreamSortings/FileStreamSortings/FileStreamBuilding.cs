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
        private const int COL_MAX_SIZE = 0x0040;

        // non-static fields

        public readonly string path;
        private List<StringPosInFile> positions;
        private int[] sortedNames, sortedSurnames, sortedIDs;
        private bool isNamesSorted, isSurnamesSorted, isIDsSorted;
        private KeyGeneration GenerateKey;
        private GetValues GetNames, GetSurnames, GetIDs;

        // constructor

        public FileStreamBuilding(string path_)
        {     
            byte[] buffer = new byte[BUF_SIZE];
            positions = new List<StringPosInFile>();
            path = path_;

            using (FileStream file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                file.Seek(3, SeekOrigin.Begin); // skipping BOM

                int startOfString = (int)file.Position, endOfString = 0, currentFilePos = 0, readBytes = 0;

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

                            if (checkRecord(buffer, currentFilePos, startOfString, endOfString) == false)
                            {
                                throw new FormatInFileException("In FileStreamBuilding.FileStreamBulding(): format of record in file is wrong.", file);
                            }

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
                    if (checkRecord(buffer, currentFilePos, startOfString, (int)file.Length) == false)
                    {
                        throw new FormatInFileException("In FileStreamBuilding.FileStreamBulding(): format of record in file is wrong.", file);
                    }

                    positions.Add(new StringPosInFile(startOfString, (int)file.Length));
                }
            }

            SetDelegates();
        }

        // non-static methods

        private bool checkRecord(byte[] sourceArray, int currentPosInFile, int absoluteStartIndex, int absoluteEndIndex)
        {
            byte[] destArray = new byte[absoluteEndIndex - absoluteStartIndex];
            Array.Copy(sourceArray, absoluteStartIndex - currentPosInFile, destArray, 0, destArray.Length);

            if (destArray.Length > COL_MAX_SIZE * 3)
            {
                return false;
            }
            else
            {
                string record = Encoding.UTF8.GetString(destArray);
                string[] records = record.Split(new char[] { ' ' });
                if (records.Length == 3 && records.Contains("") == false)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }

        private void SetGenerateKeyDelegate ()
        {
            GenerateKey = delegate(ComparingValues valuesToCompare)
            {
                int[] valuesToSort = new int[positions.Count];

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

        private void SetGetNamesDelegate()
        {
            GetNames = delegate(ref List<Record> storage, string valueToCompare, int binarySearchIndex)
            {
                Record recordBuffer;

                while (binarySearchIndex > 0)
                {
                    recordBuffer = new Record(path, positions[sortedNames[binarySearchIndex - 1]]);
                    if (recordBuffer.name != valueToCompare)
                    {
                        break;
                    }
                    --binarySearchIndex;
                }

                while (binarySearchIndex < sortedNames.Length)
                {
                    recordBuffer = new Record(path, positions[sortedNames[binarySearchIndex]]);

                    if (recordBuffer.name != valueToCompare)
                    {
                        break;
                    }
                    else
                    {
                        storage.Add(recordBuffer);
                        ++binarySearchIndex;
                    }
                }
            };
        }

        private void SetGetSurnamesDelegate()
        {
            GetSurnames = delegate(ref List<Record> storage, string valueToCompare, int binarySearchIndex)
            {
                Record recordBuffer;

                while (binarySearchIndex > 0)
                {
                    recordBuffer = new Record(path, positions[sortedSurnames[binarySearchIndex - 1]]);
                    if (recordBuffer.surname != valueToCompare)
                    {
                        break;
                    }
                    --binarySearchIndex;
                }

                while (binarySearchIndex < sortedSurnames.Length)
                {
                    recordBuffer = new Record(path, positions[sortedSurnames[binarySearchIndex]]);

                    if (recordBuffer.surname != valueToCompare)
                    {
                        break;
                    }
                    else
                    {
                        storage.Add(recordBuffer);
                        ++binarySearchIndex;
                    }
                }
            };
        }

        private void SetGetIDsDelegate()
        {
            GetIDs = delegate(ref List<Record> storage, string valueToCompare, int binarySearchIndex)
            {
                Record recordBuffer;

                while (binarySearchIndex > 0)
                {
                    recordBuffer = new Record(path, positions[sortedIDs[binarySearchIndex - 1]]);
                    if (recordBuffer.id != valueToCompare)
                    {
                        break;
                    }
                    --binarySearchIndex;
                }

                while (binarySearchIndex < sortedIDs.Length)
                {
                    recordBuffer = new Record(path, positions[sortedIDs[binarySearchIndex]]);

                    if (recordBuffer.id != valueToCompare)
                    {
                        break;
                    }
                    else
                    {
                        storage.Add(recordBuffer);
                        ++binarySearchIndex;
                    }
                }
            };
        }

        private void SetDelegates()
        {
            SetGenerateKeyDelegate();
            SetGetNamesDelegate();
            SetGetSurnamesDelegate();
            SetGetIDsDelegate();
        }

        // print all data base item to console
        public void ShowAll()
        {
            byte[] buffer;

            using (FileStream file = new FileStream(path, FileMode.Open, FileAccess.Read, FileShare.ReadWrite))
            {
                foreach (var str in positions)
                {
                    file.Seek(str.begin, SeekOrigin.Begin);
                    buffer = new byte[str.end - str.begin];
                    file.Read(buffer, 0, buffer.Length);
                    Console.WriteLine(Encoding.UTF8.GetString(buffer));
                }
            }
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
                GetNames(ref result, name, index);
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
                GetSurnames(ref result, surname, index);
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
                GetIDs(ref result, id, index);
            }

            return result;
        }
    }
}
