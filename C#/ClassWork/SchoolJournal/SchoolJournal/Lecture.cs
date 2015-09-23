using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class Lecture
    {
        // non-static fields

        public Subject subject;
        public string subjectTopic;
        public Teacher teacher;
        public StudyGroup studyGroup;
        public List<Mark> marks;

        // contructors 

        public Lecture()
        {
            subject = default(Subject);
            subjectTopic = default(string);
            teacher = default(Teacher);
            studyGroup = default(StudyGroup);
            marks = default(List<Mark>);
        }

        public Lecture(Subject subject_, string subjectTopic_, Teacher teacher_, StudyGroup studyGroup_)
        {
            subject = subject_;
            subjectTopic = subjectTopic_;
            teacher = teacher_;
            studyGroup = studyGroup_;
            marks = default(List<Mark>);
        }
    }
}
