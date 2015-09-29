using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    public static class Recoverings
    {
        // extension methods for recovering

        public static void Recover(this List<StudyGroup> studyGroups, List<Pupil> pupils)
        {
            foreach (StudyGroup studyGroup in studyGroups)
            {
                var appropriatePupils = from id in studyGroup.pupilIDs
                                        join pupil in pupils
                                        on id
                                        equals pupil.PupilID
                                        select pupil;

                foreach (Pupil pupil in appropriatePupils)
                {
                    studyGroup.listOfPupils.Add(pupil);
                }
            }
        }

        public static void Recover(this List<Lecture> lectures, List<StudyGroup> groups, List<Subject> subjects, List<Teacher> teachers, List<Pupil> pupils)
        {
            foreach (Lecture lecture in lectures)
            {
                // recovering teacher

                lecture.teacher = teachers.Single(teacher => teacher.TeacherID == lecture.teacherID);

                // recovering group

                foreach (StudyGroup group in groups)
                {
                    if (lecture.groupID == group.GroupID)
                    {
                        lecture.studyGroup = group;
                        break;
                    }
                }

                // recovering subject

                foreach (Subject subject in subjects)
                {
                    if (lecture.subjectID == subject.SubjectID)
                    {
                        lecture.subject = subject;
                        break;
                    }
                }

                // recovering marks

                var appropriateTeachersForMarks = from mark in lecture.marks
                                                  join teacher in teachers
                                                  on mark.teacherID
                                                  equals teacher.TeacherID
                                                  select teacher;

                var appropriatePupilsForMarks = from mark in lecture.marks
                                                join pupil in pupils
                                                on mark.pupilID
                                                equals pupil.PupilID
                                                select pupil;

                for (int i = 0; i < lecture.marks.Count; ++i)
                {
                    lecture.marks[i].teacher = appropriateTeachersForMarks.ElementAt(i);
                    lecture.marks[i].pupil = appropriatePupilsForMarks.ElementAt(i);
                }
            }
        }
    }
}
