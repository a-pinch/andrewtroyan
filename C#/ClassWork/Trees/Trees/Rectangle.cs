using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Trees
{
    [Serializable]
    public class Rectangle
    {
        // non-static fields

        [XmlElement(ElementName = "x")]
        public int x;
        [XmlElement(ElementName = "y")]
        public int y;
        [XmlElement(ElementName = "width")]
        public int width;
        [XmlElement(ElementName = "height")]
        public int height;

        // constructor

        public Rectangle() { }

        public Rectangle(int x_, int y_, int width_, int height_)
        {
            x = x_;
            y = y_;
            width = width_;
            height = height_;
        }
    }
}
