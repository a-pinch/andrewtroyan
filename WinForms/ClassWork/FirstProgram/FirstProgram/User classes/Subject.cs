using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FirstProgram
{
    class Subject
    {
        // static members

        public static XmlDocument xmlDocument;

        static Subject()
        {
            xmlDocument = new XmlDocument();
            xmlDocument.Load(Data.subjectsLocation);
        }
    }
}
