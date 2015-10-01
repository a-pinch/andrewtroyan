using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;
using System.Xml.XPath;
using System.Xml.Xsl;
using System.Xml;

namespace Trees
{
    class Program
    {
        static void Main(string[] args)
        {
            Wood test = new Wood(2000, 3000);
            test.GenerateWood();
            test.GenerateSnow();

            XmlSerializer serializer = new XmlSerializer(typeof(Wood));
            using (var file = new StreamWriter("..\\..\\test.xml"))
            {
                serializer.Serialize(file, test);
            }

            XPathDocument myXPathDoc = new XPathDocument("..\\..\\test.xml");
            XslTransform myXslTrans = new XslTransform();
            myXslTrans.Load("..\\..\\style.xsl");
            XmlTextWriter myWriter = new XmlTextWriter("..\\..\\result.html", null);
            myXslTrans.Transform(myXPathDoc, null, myWriter);
        }
    }
}
