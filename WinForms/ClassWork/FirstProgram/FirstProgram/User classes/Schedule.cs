using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FirstProgram
{
    class Schedule
    {
        // static members

        public static XmlDocument xmlDocument;

        static Schedule()
        {
            xmlDocument = new XmlDocument();
            xmlDocument.Load(Data.scheduleLocation);
        }
    }
}
