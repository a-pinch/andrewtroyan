using System;
using System.IO;
using System.Text;

namespace FileStreamExample
{
    class Program
    {
        // Демонстрационный пример 
        // работы с классом FileStream
        static void Main(string[] args)
        {
            // Получаем путь к файлу
            Console.WriteLine("Введите путь к файлу:");
            string filePath = Console.ReadLine();
            // Создаем объект FileStream - 
            // коментарии к конструктору см. ниже в уроке
            // Использование блока using позволяет правильно
            // разрушить FileStream
            using (FileStream fs = new FileStream(filePath,
                FileMode.Create, FileAccess.ReadWrite, FileShare.ReadWrite))
            {
                // Получаем данные для записи в файл
                Console.WriteLine("Введите строку для записи в файл:");
                string writeText = Console.ReadLine();
                // Преобразуем строку в массив байт,
                // т.к. FileStream умеет работать только с байтами
                byte[] writeBytes = Encoding.UTF8.GetBytes(writeText);
                // Запишем данные в файл
                fs.Write(writeBytes, 0, writeBytes.Length);
                // Сохраним данные из буфера на диск
                fs.Flush();
                // Теперь прочитаем данные из файла
                // для этого нужно сначала установить курсор 
                // на начало файла
                fs.Seek(0, SeekOrigin.Begin);
                // Теперь прочитаем данные в другой массив байт
                byte[] readBytes = new byte[(int)fs.Length/*до конца файла*/];
                fs.Read(readBytes, 0, readBytes.Length);
                // Преобразуем байты в строку
                string readText = Encoding.UTF8.GetString(readBytes);
                // Выведем ее на консоль
                Console.WriteLine("Данные, прочитанные из файла: {0}", readText);
            }
            Console.Read();
        }
    }
}
