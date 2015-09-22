using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FirstXMLWork
{
    class Program
    {
        static void Main(string[] args)
        {
            XmlDocument doc = new XmlDocument();
            doc.Load(@"..\\..\\Cars.xml");
            XmlNode root = doc.ChildNodes[1];
            //NodeWorking.displayNode(root);

            List<Automobile> automobiles = new List<Automobile>();

            var children = root.ChildNodes;

            foreach (XmlNode child in children)
            {
                if (child.Name.ToLower() == "car")
                {
                    automobiles.Add(new Automobile(child));
                }
            }

            var ordering = from auto in automobiles
                           orderby auto.year descending
                           select auto;

            var mostNewCar = ordering.First();

            Automobile testForRecording = new Automobile("USA", "Impala", "Red", 1967, 100, "7sbj2k21", "13.jpg", automobiles[0]);
            testForRecording.addToXMLAsChild(doc, root);
            doc.Save(@"..\\..\\Cars.xml");

            Console.ReadKey();
        }
    }
}
