using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace FileTree
{
    // provides different work with files and directories (viewing in the tree shape, replacing / looking for phrases
    // in all files in the given directory)

    class FileWorking
    {
        // static methods

        // shows all directories and file in the given directory
        public static void ShowDirectories(string startPath, string branches = "")
        {
            if (Directory.Exists(startPath) == false)
            {
                throw new DirectoryNotFoundException("In FileWorking.ShowDirectory(string): the start path doesn't exist.");
            }

            var directories = Directory.EnumerateDirectories(startPath);

            var iterator = directories.GetEnumerator();
            bool notLast = iterator.MoveNext();
            string directoryPath = "";

            while (notLast)
            {
                directoryPath = iterator.Current;
                notLast = iterator.MoveNext();

                // first of all we print current directory
                ShowDirectory(directoryPath, notLast == true ? branches + "├────" : branches + "└────");

                var files = Directory.EnumerateFiles(directoryPath);

                // then we print files in this directory (if there are any of them)
                if (files.Any())
                {
                    string adding = (notLast == true) ? "│    " : "     ";
                    adding += (Directory.EnumerateDirectories(directoryPath).Any() == true) ? "│   " : "    ";

                    foreach (var file in files)
                    {
                        ShowDirectory(file, branches + adding);
                    }

                    Console.WriteLine(branches + adding);
                }

                // and then we print the rest of directories (recursively)
                ShowDirectories(directoryPath, notLast == true ? branches + "│    " : branches + "     ");
            }
        }

        // crops absolute path to the file (name of file and extension only remaining)
        private static string Crop(string fileName)
        {
            int indexOfLastSlash = fileName.LastIndexOf(@"\");
            return fileName.Substring(indexOfLastSlash + 1);
        }

        // helping method for ShowDirectories(string, string)
        // just prints the name of file with adding string before the name
        private static void ShowDirectory(string startPath, string branches)
        {
            string croppedPath = Crop(startPath);
            Console.WriteLine(branches + croppedPath);
        }

        // looks for the phrase in files (except nested ones) in the given directory and replaces it 
        public static void FindAndReplace(string path, string toBeReplaced, string toReplace)
        {
            if (Directory.Exists(path) == false)
            {
                throw new DirectoryNotFoundException("In FileWorking.FindAndReplace(string, string, string): the start path doesn't exist.");
            }

            var filePaths = Directory.EnumerateFiles(path);

            foreach (var filePath in filePaths)
            {
                // we work on txt files only
                if (Path.GetExtension(filePath) == ".txt")
                {
                    ReplaceInFile(filePath, toBeReplaced, toReplace);
                }
            }
        }

        // helping method for FindAndReplace(string, string, string)
        // replaces the phrase in one file
        private static void ReplaceInFile(string path, string toBeReplaced, string toReplace)
        {
            string buffer = "";
            bool isChanged = false;
            int indexOfMatching;

            using (StreamReader from = new StreamReader(path))
            // creating temporary file
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

            // if we made any changes (if we found the given phrase)
            if (isChanged == true)
            {
                // delete original file
                File.Delete(path);
                // rename terminal file
                File.Move(path + ".tmp", path);
            }
            else
            {
                File.Delete(path + ".tmp");
            }
        }

        // looks for the phrase in the given directory and returns a dictionaty with file's name and 
        // indices of strings where the phrase was found in this file
        // warning! the dictionary may include file's name with no indices (that means the phrase wasn't found in this file)
        public static Dictionary<string, List<int>> Find(string path, string toFind)
        {
            if (Directory.Exists(path) == false)
            {
                throw new DirectoryNotFoundException("In FileWorking.Find(string, string): the given path doesn't exist.");
            }

            var group = from file in Directory.EnumerateFiles(path)
                        where (Path.GetExtension(file) == ".txt")
                        let indices = FindInFile(file, toFind)
                        select new { FileName = Crop(file), Indices = indices };

            return group.ToDictionary(item => item.FileName, item => item.Indices);
        }

        // helping method for Find(string, string)
        // looks for the phrase in one file
        private static List<int> FindInFile(string path, string ToFind)
        {
            List<int> indices = new List<int>();
            string buffer = "";
            int currentIndex = 0;

            using (StreamReader file = new StreamReader(path))
            {
                while (file.EndOfStream == false)
                {
                    buffer = file.ReadLine();

                    if (buffer.IndexOf(ToFind) >= 0)
                    {
                        indices.Add(currentIndex);
                    }

                    ++currentIndex;
                }
            }

            return indices;
        }
    }
}
