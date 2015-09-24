using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    [Serializable]
    public class Lecture
    {
        // non-static fields

        [XmlIgnore] public Subject subject;
        public string subjectTopic;
        [XmlIgnore] public Teacher teacher;
        public int teacherID;
        [XmlIgnore] public StudyGroup studyGroup;
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
            if (subject_.topics.Contains(subjectTopic_) == false)
            {
                throw new InvalidOperationException("In Lecture.Lecture(Subject, string, Teacher, StudyGroup): there isn't given topic in subject's topics.");
            }

            subject = subject_;
            subjectTopic = subjectTopic_;
            teacher = teacher_;
            studyGroup = studyGroup_;
            marks = new List<Mark>();
        }
    }
}
