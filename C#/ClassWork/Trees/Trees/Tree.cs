using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Trees
{
    [Serializable]
    public class Tree
    {
        // non-static fields

        [XmlElement(ElementName = "layer")]
        public List<Triangle> layers;
        public Rectangle trunk;

        // constructors

        public Tree() { }

        public Tree(int posX, int posY, int width, int height, int amountOfLayers)
        {
            layers = new List<Triangle>();

            int widthOfTrunk = amountOfLayers * amountOfLayers;
            int heightOfTrunk = widthOfTrunk * 2 / 3;
            trunk = new Rectangle(posX + width / 2 - widthOfTrunk / 2, posY + height - heightOfTrunk, widthOfTrunk, heightOfTrunk);

            int heightForTriangle = (height - heightOfTrunk) / amountOfLayers + 1;

            int[] firstPoint = new int[2] { width / 2 + posX, posY };
            int[] secondPoint = new int[2] { width + posX, posY + heightForTriangle };
            int[] thirdPoint = new int[2] { posX, posY + heightForTriangle };

            for (int i = 0; i < amountOfLayers; ++i)
            {
                layers.Add(new Triangle(firstPoint, secondPoint, thirdPoint));
                firstPoint[1] += heightForTriangle;
                secondPoint[1] += heightForTriangle;
                thirdPoint[1] += heightForTriangle;
            }
        }
    }
}
