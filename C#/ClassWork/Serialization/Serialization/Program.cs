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
            Schooler schoolerIrina = new Schooler("Irina", new int[] { 9, 10, 8, 9 }, new string[] { "pen", "pensil" });
            Schooler deserializedSchooler;

            #region XML serialization

            //var xmlSerializator = new XmlSerializer(typeof(Schooler));

            //using (var toXml = new StreamWriter(@"..\..\testWithSchoolersXML.xml"))
            //{
            //    xmlSerializator.Serialize(toXml, schoolerIrina);
            //}

            //using (var fromXML = new StreamReader(@"..\..\testWithSchoolersXML.xml"))
            //{
            //    deserializedSchooler = (Schooler)xmlSerializator.Deserialize(fromXML);
            //}

            //Console.WriteLine("Name: {0}.\nMarks: {1}.\nPen case: {2}.", deserializedSchooler._name, String.Join(", ", deserializedSchooler._marks)
            //    , String.Join(", ", deserializedSchooler._penCase));


            #endregion

            #region Binary serialization

            BinaryFormatter binarySerializer = new BinaryFormatter();

            using (var toBIN = File.Create(@"..\..\testWithSchoolersXML.bin"))
            {
                binarySerializer.Serialize(toBIN, schoolerIrina);
            }

            using (var fromBIN = File.OpenRead(@"..\..\testWithSchoolersXML.bin"))
            {
                deserializedSchooler = (Schooler)binarySerializer.Deserialize(fromBIN);
            }

            Console.WriteLine("Name: {0}.\nMarks: {1}.\nPen case: {2}.", deserializedSchooler._name, String.Join(", ", deserializedSchooler._marks)
                , String.Join(", ", deserializedSchooler._penCase));

            #endregion 

            Console.ReadKey();
        }
    }
}
