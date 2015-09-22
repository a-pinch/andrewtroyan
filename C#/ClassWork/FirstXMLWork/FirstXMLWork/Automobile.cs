using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FirstXMLWork
{
    class Automobile
    {
        // non-static fields

        public readonly string manufactured;
        public readonly string model;
        public readonly string hash;
        public string image;
        public string color;
        public readonly int year;
        public int speed;
        public Automobile inner;

        // constructors

        public Automobile(XmlNode xmlAuto)
        {
            var attributes = xmlAuto.Attributes;

            foreach (XmlAttribute attr in attributes)
            {
                switch (attr.Name.ToLower())
                {
                    case "image":
                        image = attr.Value;
                        break;

                    case "color":
                        color = attr.Value;
                        break;

                    case "year":
                        year = int.Parse(attr.Value);
                        break;

                    case "hash":
                        hash = attr.Value;
                        break;
                }
            }

            var children = xmlAuto.ChildNodes;

            foreach (XmlNode child in children)
            {
                switch (child.Name.ToLower())
                {
                    case "manufactured":
                        manufactured = child.ChildNodes[0].Value;
                        break;

                    case "model":
                        model = child.ChildNodes[0].Value;
                        break;

                    case "year":
                        year = int.Parse(child.ChildNodes[0].Value);
                        break;

                    case "color":
                        color = child.ChildNodes[0].Value;

                        var attr = child.Attributes;

                        if (attr.Count > 0 && attr["metallic"] != null && attr["metallic"].Value == "true")
                        {
                            color += ", metallic";
                        }

                        break;

                    case "speed":
                        speed = int.Parse(child.ChildNodes[0].Value);
                        break;

                    case "inside":
                        inner = new Automobile(child.ChildNodes[0]);
                        break;
                }
            }
        }

        public Automobile(string manufactured_, string model_, string color_, int year_, int speed_, string hash_ = null, string image_ = null, Automobile inner_ = null)
        {
            manufactured = manufactured_;
            model = model_;
            color = color_;
            year = year_;
            speed = speed_;
            hash = hash_;
            image = image_;
            inner = inner_;
        }

        // non-static methods

        public void addToXMLAsChild(XmlDocument doc, XmlNode parent)
        {
            var car = doc.CreateElement("Car");

            if (image != null)
            {
                car.SetAttribute("Image", image);
            }

            var child = doc.CreateElement("Manufactured");
            child.AppendChild(doc.CreateTextNode(manufactured));
            car.AppendChild(child);

            child = doc.CreateElement("Color");
            child.AppendChild(doc.CreateTextNode(color));
            car.AppendChild(child);

            child = doc.CreateElement("Model");
            child.AppendChild(doc.CreateTextNode(model));
            car.AppendChild(child);

            child = doc.CreateElement("Year");
            child.AppendChild(doc.CreateTextNode(year.ToString()));
            car.AppendChild(child);

            child = doc.CreateElement("Speed");
            child.AppendChild(doc.CreateTextNode(speed.ToString()));
            car.AppendChild(child);

            if (hash != null)
            {
                child = doc.CreateElement("Hash");
                child.AppendChild(doc.CreateTextNode(hash));
                car.AppendChild(child);
            }

            if (inner != null)
            {
                child = doc.CreateElement("Inner");
                inner.addToXMLAsChild(doc, child);
                car.AppendChild(child);
            }
            
            parent.AppendChild(car);
        }
    }
}
