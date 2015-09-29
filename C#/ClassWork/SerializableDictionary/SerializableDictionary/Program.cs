using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;

namespace SerializableDictionary
{
    class Program
    {
        static void Main(string[] args)
        {
            MySortedDictionary<string, List<int>> eventsToSerialize = new MySortedDictionary<string, List<int>>();
            eventsToSerialize["New Year"] = new List<int>(){31, 12};
            eventsToSerialize["Christmas"] = new List<int>(){7, 1};

            XmlSerializer serializer = new XmlSerializer(typeof(MySortedDictionary<string, List<int>>));

            using (var file = new StreamWriter("..\\..\\test.xml"))
            {
                serializer.Serialize(file, eventsToSerialize);
            }

            MySortedDictionary<string, List<int>> deserializedEvents = new MySortedDictionary<string, List<int>>();

            using (var file = new StreamReader("..\\..\\test.xml"))
            {
                deserializedEvents = (MySortedDictionary<string, List<int>>)serializer.Deserialize(file);
            }

            foreach (var node in deserializedEvents)
            {
                Console.WriteLine("Event: " + node.Key);
                Console.WriteLine("Date: " + node.Value[0] + "." + node.Value[1]);
            }

            Console.ReadKey();
        }
    }
}
