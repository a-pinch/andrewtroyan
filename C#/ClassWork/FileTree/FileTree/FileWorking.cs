using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileTree
{
    class FileWorking
    {
        // static methods

        public static void ShowDirectories(string startPath, string branches = "")
        {
            if (Directory.Exists(startPath) == false)
            {
                throw new DirectoryNotFoundException("In FileWorking.ShowDirectory(string): the start path doesn't exist.");
            }

            var directories = from directory in Directory.EnumerateDirectories(startPath)
                              select directory;

            var iterator = directories.GetEnumerator();
            bool notLast = iterator.MoveNext();

            while (notLast)
            {
                var directoryPath = iterator.Current;

                notLast = iterator.MoveNext();

                if (notLast == false)
                {
                    ShowDirectory(directoryPath, branches + "└────");
                    ShowDirectories(directoryPath, branches + "     ");
                }
                else
                {
                    ShowDirectory(directoryPath, branches + "├────");
                    ShowDirectories(directoryPath, branches + "│    ");
                }
            }
        }

        private static void ShowDirectory(string startPath, string branches)
        {
            int indexOfLastSlash = startPath.LastIndexOf(@"\");
            startPath = startPath.Substring(indexOfLastSlash + 1);

            Console.WriteLine(branches + startPath);
        }

        public static void FindAndReplace(string path, string toBeReplaced, string toReplace)
        {
            if (Directory.Exists(path) == false)
            {
                throw new DirectoryNotFoundException("In FileWorking.FindAndReplace(string, string, string): the start path doesn't exist.");
            }

            var filePaths = from filePath in Directory.EnumerateFiles(path)
                            select filePath;

            foreach (var filePath in filePaths)
            {
                if (Path.GetExtension(filePath) == ".txt")
                {
                    ReplaceInFile(filePath, toBeReplaced, toReplace);
                }
            }
        }

        private static void ReplaceInFile(string path, string toBeReplaced, string toReplace)
        {
            string buffer = "";
            bool isChanged = false;
            int indexOfMatching;

            using (StreamReader from = new StreamReader(path))
            using (StreamWriter to = new StreamWriter(path + ".tmp"))
            {
                while (from.EndOfStream == false)
                {
                    buffer = from.ReadLine();

                    while ((indexOfMatching = buffer.IndexOf(toBeReplaced)) >= 0)
                    {
                        buffer = buffer.Substring(0, indexOfMatching) + toReplace + buffer.Substring(indexOfMatching + toBeReplaced.Length);
                        isChanged = true;
                    }

                    to.WriteLine(buffer);
                }
            }

            if (isChanged == true)
            {
                File.Delete(path);
                File.Move(path + ".tmp", path);
            }
            else
            {
                File.Delete(path + ".tmp");
            }
        }
    }
}
