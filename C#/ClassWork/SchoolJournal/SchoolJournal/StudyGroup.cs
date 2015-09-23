using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class StudyGroup
    {
        // non-static fields

        public string name;
        public List<Pupil> listOfPupils;

        // constructors

        public StudyGroup()
        {
            name = default(string);
            listOfPupils = default(List<Pupil>);
        }

        public StudyGroup(string name_, List<Pupil> listOfPupils_)
        {
            name = name_;
            listOfPupils = listOfPupils_;
        }
    }
}
