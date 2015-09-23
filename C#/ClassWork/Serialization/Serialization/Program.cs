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
    class Program
    {
        static void Main(string[] args)
        {
            List<Schooler> schoolers = new List<Schooler>();
            schoolers.Add(new Schooler("Irina", new int[] { 9, 10, 8, 9 }, new string[] { "pen", "pensil" }));
            schoolers.Add(new Schooler("Vadim", new int[] { 10, 10, 10, 10 }, new string[] { "pensil" }));
            int listSize = schoolers.Count;

            Schooler deserializedSchooler;

            #region XML serialization

            string path = "..\\..\\XmlSerializedSchoolers\\schooler";
            var xmlSerializator = new XmlSerializer(typeof(Schooler));

            for (int i = 0; i < listSize; ++i)
            {
                using (var toXml = new StreamWriter(path + i + ".xml"))
                {
                    xmlSerializator.Serialize(toXml, schoolers[i]);
                }
            }

            for (int i = 0; i < listSize; ++i)
            {
                using (var fromXml = new StreamReader(path + i + ".xml"))
                {
                    deserializedSchooler = (Schooler)xmlSerializator.Deserialize(fromXml);
                }

                Console.WriteLine("Name: {0}.\nMarks: {1}.\nPen case: {2}.\n", deserializedSchooler._name, String.Join(", ", deserializedSchooler._marks)
                , String.Join(", ", deserializedSchooler._penCase));
            }

            #endregion

            #region Binary serialization

            //BinaryFormatter binarySerializer = new BinaryFormatter();

            //using (var toBIN = File.Create(@"..\..\testWithSchoolersXML.bin"))
            //{
            //    binarySerializer.Serialize(toBIN, schoolerIrina);
            //}

            //using (var fromBIN = File.OpenRead(@"..\..\testWithSchoolersXML.bin"))
            //{
            //    deserializedSchooler = (Schooler)binarySerializer.Deserialize(fromBIN);
            //}

            //Console.WriteLine("Name: {0}.\nMarks: {1}.\nPen case: {2}.", deserializedSchooler._name, String.Join(", ", deserializedSchooler._marks)
            //    , String.Join(", ", deserializedSchooler._penCase));

            #endregion 

            Console.ReadKey();
        }
    }
}
