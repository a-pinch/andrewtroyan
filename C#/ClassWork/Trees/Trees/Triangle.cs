using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Trees
{
    [Serializable]
    public class Triangle
    {
        // non-static fields

        [XmlElement(ElementName = "firstPointX")]
        public int firstPointX;
        [XmlElement(ElementName = "firstPointY")]
        public int firstPointY;
        [XmlElement(ElementName = "secondPointX")]
        public int secondPointX;
        [XmlElement(ElementName = "secondPointY")]
        public int secondPointY;
        [XmlElement(ElementName = "thirdPointX")]
        public int thirdPointX;
        [XmlElement(ElementName = "thirdPointY")]
        public int thirdPointY;

        // constructors

        public Triangle() { }

        public Triangle(int[] firstPoint_, int[] secondPoint_, int[] thirdPoint_)
        {
            firstPointX = firstPoint_[0];
            firstPointY = firstPoint_[1];
            secondPointX = secondPoint_[0];
            secondPointY = secondPoint_[1];
            thirdPointX = thirdPoint_[0];
            thirdPointY = thirdPoint_[1];
        }
    }
}
