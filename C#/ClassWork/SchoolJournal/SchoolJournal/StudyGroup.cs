using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    [Serializable]
    public class StudyGroup
    {
        // static fields

        private static int currentID = 0;

        // non-static fields

        public string name;
        [XmlIgnore]
        public List<Pupil> listOfPupils;
        public List<int> pupilIDs;
        private int groupID;

        // properties

        [XmlAttribute]
        public int GroupID
        {
            get { return groupID; }
            set
            {
                groupID = value;

                if (value >= currentID)
                {
                    currentID = value + 1;
                }
            }
        }

        // constructors

        public StudyGroup()
        {
            name = default(string);
            listOfPupils = new List<Pupil>();
            pupilIDs = new List<int>();
            groupID = currentID++;
        }

        public StudyGroup(string name_, List<Pupil> listOfPupils_) : this()
        {
            name = name_;
            listOfPupils = listOfPupils_;

            foreach (var pupil in listOfPupils)
            {
                pupilIDs.Add(pupil.PupilID);
            }
        }
    }
}
