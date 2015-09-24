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
        //// static fields

        //private static int commonId = 0;

        //// non-static fields

        //private int teacherId;

        //// properties

        //[XmlAttribute]
        //public int TeacherId
        //{
        //    get
        //    {
        //        return teacherId;
        //    }
        //    set
        //    {
        //        teacherId = value;

        //        if (value >= teacherId)
        //        {
        //            commonId = value + 1;
        //        }
        //    }
        //}

        // constructors

        public Teacher()
        {
            name = default(string);
            //teacherId = commonId++;
        }

        public Teacher(string name_) : this()
        {
            name = name_;
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
