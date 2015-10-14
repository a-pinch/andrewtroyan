using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FirstProgram
{
    class Pupil
    {
        // static members

        public static XmlDocument xmlDocument;

        static Pupil()
        {
            xmlDocument = new XmlDocument();
            xmlDocument.Load(Data.pupilsLocation);
        }
    }
}
