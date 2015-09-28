using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    [Serializable]
    public class Pupil : Human
    {
        // static fields

        private static int currentID = 0;

        // non-static fields

        private int pupilID;

        // properties 

        [XmlAttribute]
        public int PupilID
        {
            get { return pupilID; }
            set
            {
                pupilID = value;

                if (value >= currentID)
                {
                    currentID = value + 1;
                }
            }
        }

        // constructors

        public Pupil()
        {
            name = default(string);
            pupilID = currentID++;
        }

        public Pupil(string name_, string surname_) : this()
        {
            name = name_;
            surname = surname_;
        }
    }
}
