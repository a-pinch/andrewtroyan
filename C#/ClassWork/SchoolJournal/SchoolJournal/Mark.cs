using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    // ground of a given mark
    [Serializable]
    public enum MarkGround
    {
        homework,
        board,
        controlwork
    }

    [Serializable]
    public class Mark
    {
        // non-static fields

        public int point;
        public MarkGround markGround;
        [XmlIgnore] public Pupil pupil;
        public int pupilID;
        [XmlIgnore] public Teacher teacher;
        public int teacherID;

        // constructors

        public Mark()
        {
            point = default(int);
            markGround = default(MarkGround);
            pupil = default(Pupil);
            pupilID = default(int);
            teacher = default(Teacher);
            teacherID = default(int);
        }

        public Mark(int point_, Pupil pupil_, Teacher teacher_, MarkGround markGround_)
        {
            point = point_;
            pupil = pupil_;
            pupilID = pupil_.PupilID;
            teacher = teacher_;
            teacherID = teacher_.TeacherID;
            markGround = markGround_;
        }
    }
}
