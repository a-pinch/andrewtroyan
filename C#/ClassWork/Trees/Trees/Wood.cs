using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Trees
{
    [Serializable]
    public class Wood
    {
        // non-static fields

        [XmlAttribute]
        public int height;
        [XmlAttribute]
        public int width;
        [XmlElement(ElementName = "tree")]
        public List<Tree> trees;

        // constructors

        public Wood() { }

        public Wood(int height_, int width_)
        {
            height = height_;
            width = width_;
            trees = new List<Tree>();
        }

        // non-static fields
        public void GenerateWood()
        {
            Random rand = new Random();
            int amountOfTrees = rand.Next(50, 100);
            int maxWidthOfTree = width / 25;
            int maxHightOfTree = height / 10;
            int posX, posY;

            for (int i = 0; i < amountOfTrees; ++i)
            {
                posX = rand.Next(width - maxWidthOfTree);
                posY = rand.Next(height - maxHightOfTree);

                trees.Add(new Tree(posX, posY, maxWidthOfTree, maxHightOfTree, rand.Next(3, 6)));
            }
        }
    }
}
