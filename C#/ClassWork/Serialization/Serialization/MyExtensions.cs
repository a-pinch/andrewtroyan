using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Runtime.Serialization.Formatters.Binary;
using System.IO;

namespace Serialization
{
    // --- provides extension methods for List<Schooler> and also static methods of List<Schooler> deserialization

    public static class MyExtensions
    {
        // --- extention methods 

        // prints information about schoolers to the console
        public static void PrintOut(this List<Schooler> schoolers)
        {
            foreach (var schooler in schoolers)
            {
                schooler.PirntOut();
                Console.WriteLine();
            }
        }

        // serializes given schooler's info to xml file
        public static void SerializeToXml(this List<Schooler> schoolers, string path)
        {
            if (Path.GetExtension(path) != ".xml")
            {
                throw new InvalidDataException("In MyExtensions.SerializeToXml(this List<Schooler>, string): the extension must be \".xml\".");
            }

            XmlSerializer xmlSerializer = new XmlSerializer(typeof(List<Schooler>));

            using (var fileTo = new StreamWriter(path))
            {
                xmlSerializer.Serialize(fileTo, schoolers);
            }
        }

        // serializes given schooler's info in binary mode
        public static void SerializeBinary(this List<Schooler> schoolers, string path)
        {
            if (Path.GetExtension(path) != ".dat" && Path.GetExtension(path) != ".bin")
            {
                throw new InvalidDataException("In MyExtensions.SerializeToXml(this List<Schooler>, string): the extension must be \".dat\" or \".bin\".");
            }

            BinaryFormatter binarySerializer = new BinaryFormatter();

            using (var fileTo = File.Create(path))
            {
                binarySerializer.Serialize(fileTo, schoolers);
            }
        }

        // --- non-extension methods. I've put them here because their extension equivalents are located here

        // deserializes xml file and gets list of schoolers
        public static List<Schooler> DeserializeFromXml(string path)
        {
            if (File.Exists(path) == false)
            {
                throw new DirectoryNotFoundException("In MyExtensions.DeserializeFromXml(this List<Schooler>, string): the path doesn't exist.");
            }
            else if (Path.GetExtension(path) != ".xml")
            {
                throw new InvalidDataException("In MyExtensions.DeserializeFromXml(this List<Schooler>, string): the extension must be \".xml\".");
            }

            XmlSerializer xmlDeserializer = new XmlSerializer(typeof(List<Schooler>));
            List<Schooler> deserializedSchoolers;

            using (var filefrom = new StreamReader(path))
            {
                deserializedSchoolers = (List<Schooler>)xmlDeserializer.Deserialize(filefrom);
            }

            return deserializedSchoolers;
        }

        // deserializes bin file and gets list of schoolers
        public static List<Schooler> DeserializeBinary(string path)
        {
            if (File.Exists(path) == false)
            {
                throw new DirectoryNotFoundException("In MyExtensions.SerializeToXml(this List<Schooler>, string): the path doesn't exist.");
            }
            else if (Path.GetExtension(path) != ".dat" && Path.GetExtension(path) != ".bin")
            {
                throw new InvalidDataException("In MyExtensions.SerializeToXml(this List<Schooler>, string): the extension must be \".dat\" or \".bin\".");
            }

            BinaryFormatter binaryDeserializer = new BinaryFormatter();
            List<Schooler> deserializedSchoolers;

            using (var fileFrom = File.OpenRead(path))
            {
                deserializedSchoolers = (List<Schooler>)binaryDeserializer.Deserialize(fileFrom);
            }

            return deserializedSchoolers;
        }
    }
}
