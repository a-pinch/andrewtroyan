using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileSearch
{
    // provides retrieving most occurred words from file
    class WorkWithFile
    {
        // non-static fields

        public string filePath;

        // constructors
        
        public WorkWithFile(string filePath_)
        {
            filePath = filePath_;
        }

        // static methods

        // retrieves words from file
        private static IEnumerable<string> GetWordsFromFile(string filePath)
        {
            if (File.Exists(filePath) == false)
            {
                throw new FileNotFoundException("In WorkWithFile.GetMostOccurWord(string): file doesn't exist");
            }

            using (var file = new StreamReader(filePath))
            {
                while (file.EndOfStream == false)
                {
                    string line = file.ReadLine();
                    string[] words = line.Split(new char[] {' ', '-', '.', ',', '?', '!', '\'', '\"'}, StringSplitOptions.RemoveEmptyEntries);

                    foreach (var word in words)
                    {
                        yield return word.ToLower();
                    }
                }
            }
        }

        // non-static fields

        // retrieves the given (or less) amount of most occurred words
        public IEnumerable<string> GetMostOccurredWord(uint amountOfOccurrence)
        {
            var result = from word in GetWordsFromFile(filePath)
                         group word by word into g
                         orderby g.Count() descending
                         select g.Key;

            var enumerator = result.GetEnumerator();
            int counter = 0;

            while (counter++ < amountOfOccurrence && enumerator.MoveNext() == true)
            {
                yield return enumerator.Current;
            }
        }
    }
}
