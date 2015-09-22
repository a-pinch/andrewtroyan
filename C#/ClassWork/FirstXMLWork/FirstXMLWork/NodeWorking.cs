using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FirstXMLWork
{
    class NodeWorking
    {
        public static void displayNode(XmlNode node, int level = 0)
        {

            if (node.NodeType == XmlNodeType.Element)
            {
                Console.Write(new String(' ', level) + node.Name);
                foreach (XmlAttribute a in node.Attributes)
                {
                    Console.Write(" {0}='{1}'", a.Name, a.Value);
                }
                Console.WriteLine();

                foreach (XmlNode child in node.ChildNodes)
                {
                    displayNode(child, level + 1);
                }
            }
            else if (node.NodeType == XmlNodeType.Text)
            {
                Console.WriteLine(new String(' ', level) + '*' + node.Value + '*');
            }
        }
    }
}
