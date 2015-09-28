using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    [Serializable]
    public class Teacher : Human
    {
        // static fields

        private static int currentID = 0;

        // non-static fields

        private int teacherID;

        // properties
        
        [XmlAttribute]
        public int TeacherID
        {
            get { return teacherID; }
            set
            {
                teacherID = value;

                if (value >= currentID)
                {
                    currentID = value + 1;
                }
            }
        }

        // constructors

        public Teacher()
        {
            name = default(string);
            teacherID = currentID++;
        }

        public Teacher(string name_, string surname_) : this()
        {
            name = name_;
            surname = surname_;
        }

        // non-static methods

        public void GiveMark(Lecture lecture, Mark mark)
        {
            if (lecture.studyGroup.listOfPupils.Contains(mark.pupil) == false)
            {
                throw new InvalidOperationException("In Teacher.GiveMark(StudyGroup, Mark, Pupil): there isn't this pupil in this group.");
            }

            lecture.marks.Add(mark);
        }
    }
}
