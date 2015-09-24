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
        // non-static fields

        public string name;
        [XmlIgnore]
        public List<Pupil> listOfPupils;
        public List<int> pupilIDs;

        // constructors

        public StudyGroup()
        {
            name = default(string);
            listOfPupils = new List<Pupil>();
            pupilIDs = new List<int>();
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
