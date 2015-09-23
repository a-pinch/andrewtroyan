using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
        public Pupil pupil;
        public Teacher teacher;
        public MarkGround markGround;

        // constructors

        public Mark()
        {
            point = default(int);
            pupil = default(Pupil);
            teacher = default(Teacher);
            markGround = default(MarkGround);
        }

        public Mark(int point_, Pupil pupil_, MarkGround markGround_)
        {
            point = point_;
            pupil = pupil_;
            markGround = markGround_;
        }
    }
}
