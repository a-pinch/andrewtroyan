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

        public DateTime date;
        [XmlIgnore] public Subject subject;
        public int subjectID;
        public List<string> subjectTopics;
        [XmlIgnore] public Teacher teacher;
        public int teacherID;
        [XmlIgnore] public StudyGroup studyGroup;
        public int groupID;
        public List<Mark> marks;

        // contructors 

        public Lecture()
        {
            date = default(DateTime);
            subject = default(Subject);
            subjectTopics = default(List<string>);
            teacher = default(Teacher);
            studyGroup = default(StudyGroup);
            marks = default(List<Mark>);
        }

        public Lecture(DateTime date_, Subject subject_, List<string> subjectTopics_, Teacher teacher_, StudyGroup studyGroup_)
        {
            if (subject_.topics.Intersect(subjectTopics_).Count() != subjectTopics_.Count)
            {
                throw new InvalidOperationException("In Lecture.Lecture(Subject, List<string>, Teacher, StudyGroup): the subject contains not all of the given topics.");
            }

            date = date_;
            subject = subject_;
            subjectTopics = subjectTopics_;
            teacher = teacher_;
            teacherID = teacher_.TeacherID;
            studyGroup = studyGroup_;
            groupID = studyGroup_.GroupID;
            marks = new List<Mark>();
        }
    }
}
