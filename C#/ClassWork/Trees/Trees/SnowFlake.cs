using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Trees
{
    [Serializable]
    public class SnowFlake
    {
        // sttaic fields

        private static int index = 0;

        // non-static fields

        [XmlAttribute(AttributeName = "cx")]
        public int cx;
        [XmlAttribute(AttributeName = "cy")]
        public int cy;
        [XmlAttribute(AttributeName = "r")]
        public int r;
        [XmlAttribute(AttributeName = "id")]
        public int current;

        // constructors

        public SnowFlake() 
        {
            current = index++;
        }

        public SnowFlake(int cx_, int cy_, int r_) : this()
        {
            cx = cx_;
            cy = cy_;
            r = r_;
        }
    }
}
