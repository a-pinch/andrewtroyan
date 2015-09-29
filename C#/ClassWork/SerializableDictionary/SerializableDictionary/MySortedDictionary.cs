using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;
using System.Xml.Schema;
using System.Xml.Serialization;

namespace SerializableDictionary
{
    public class MySortedDictionary<TKey, TValue> : SortedDictionary<TKey, TValue>, IXmlSerializable
    {
        public void WriteXml(XmlWriter writer)
        {
            XmlSerializer keySerializer = new XmlSerializer(typeof(TKey));
            XmlSerializer valueSerializer = new XmlSerializer(typeof(TValue));

            foreach (KeyValuePair<TKey, TValue> node in this)
            {
                writer.WriteStartElement("node");
                writer.WriteStartElement("key");
                keySerializer.Serialize(writer, node.Key);
                writer.WriteEndElement();
                writer.WriteStartElement("value");
                valueSerializer.Serialize(writer, node.Value);
                writer.WriteEndElement();
                writer.WriteEndElement();
            }
        }

        public void ReadXml(XmlReader reader)
        {
            if (reader.IsEmptyElement)
            {
                return;
            }

            reader.Read();

            XmlSerializer keySerializer = new XmlSerializer(typeof(TKey));
            XmlSerializer valueSerializer = new XmlSerializer(typeof(TValue));
            TKey keyBuffer;
            TValue valueBuffer;

            while (reader.NodeType != XmlNodeType.EndElement) 
            {
                reader.ReadStartElement();
                reader.ReadStartElement();
                keyBuffer = (TKey)keySerializer.Deserialize(reader);
                reader.ReadEndElement();
                reader.ReadStartElement();
                valueBuffer = (TValue)valueSerializer.Deserialize(reader);
                reader.ReadEndElement();
                reader.ReadEndElement();
                this.Add(keyBuffer, valueBuffer);
                reader.MoveToContent();
            }
        }

        public XmlSchema GetSchema()
        {
            return(null);
        }
    }
}
