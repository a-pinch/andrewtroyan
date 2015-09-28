using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    [Serializable]
    public class Subject
    {
        // static field

        private static int currentID = 0;

        // non-static fields

        public string name;
        public List<string> topics;
        private int subjectID;

        // properties

        [XmlAttribute]
        public int SubjectID
        {
            get { return subjectID; }
            set
            {
                subjectID = value;

                if (value >= currentID)
                {
                    currentID = value + 1;
                }
            }
        }

        // constructors

        public Subject()
        {
            name = default(string);
            topics = new List<string>();
            subjectID = currentID++;
        }

        public Subject(string name_, List<string> topics_) : this()
        {
            name = name_;
            topics = topics_;
        }
    }
}
