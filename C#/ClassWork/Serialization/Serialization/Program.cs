using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Serialization
{
    class Program
    {
        static void Main(string[] args)
        {
            List<Schooler> schoolersToSerialize = new List<Schooler>();
            schoolersToSerialize.Add(new Schooler("Irina", new int[] { 9, 10, 8, 9 }, new string[] { "pen", "pensil" }));
            schoolersToSerialize.Add(new Schooler("Vadim", new int[] { 10, 10, 10, 10 }, new string[] { "pensil" }));

            List<Schooler> deserializedSchoolers = new List<Schooler>();

            #region XML serialization

            string pathForXml = @"..\..\XmlSerializedSchoolers.xml";
            schoolersToSerialize.SerializeToXml(pathForXml);
            deserializedSchoolers = MyExtensions.DeserializeFromXml(pathForXml);

            #endregion

            #region Binary serialization

            //string pathForBin = @"..\..\BinSerializedSchoolers.dat";
            //schoolersToSerialize.SerializeBinary(pathForBin);
            //deserializedSchoolers = MyExtensions.DeserializeBinary(pathForBin);

            #endregion

            deserializedSchoolers.PrintOut();

            Console.ReadKey();
        }
    }
}
