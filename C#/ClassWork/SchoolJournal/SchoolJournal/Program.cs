using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.IO;

namespace SchoolJournal
{
    class Program
    {
        static void Main(string[] args)
        {
            // all necessary variables

            string path = "..\\..\\Serialized\\";
            Subject subjectToSerialize, deserializedSubject;
            List<Teacher> teachersToSerialize, deserializedTeachers;
            List<Pupil> pupilsToSerialize, deserializedPupils;
            StudyGroup groupToSerialize, deserializedGroup;
            Lecture lectureToSerialize, deserializedLecture;

            #region Lecturing imitation

            subjectToSerialize = new Subject("C#", new List<string>() { "Serialization", "Attributes" });

            teachersToSerialize = new List<Teacher>() { new Teacher("Maxim"), new Teacher("Alexey") };

            pupilsToSerialize = new List<Pupil>() { new Pupil("Andrew"), new Pupil("Igor"), new Pupil("Kolya"), new Pupil("Ira"), new Pupil("Andrew")
                , new Pupil("Olya"), new Pupil("Arseniy"), new Pupil("Oleg") };

            groupToSerialize = new StudyGroup("P11014", pupilsToSerialize);

            lectureToSerialize = new Lecture(subjectToSerialize, "Serialization", teachersToSerialize[0], groupToSerialize);

            teachersToSerialize[0].GiveMark(lectureToSerialize, new Mark(10, groupToSerialize.listOfPupils[2], teachersToSerialize[0], MarkGround.homework));
            teachersToSerialize[0].GiveMark(lectureToSerialize, new Mark(8, groupToSerialize.listOfPupils[3], teachersToSerialize[0], MarkGround.board));

            #endregion

            #region Serialization

            subjectToSerialize.Serialize(path + "subject.xml");
            teachersToSerialize.Serialize(path + "teachers.xml");
            pupilsToSerialize.Serialize(path + "pupils.xml");
            groupToSerialize.Serialize(path + "group.xml");
            lectureToSerialize.Serialize(path + "lecture.xml");

            #endregion 

            #region Deserialization and connections recovering

            deserializedSubject = Deserialization.DeserializeSubject(path + "subject.xml");
            deserializedTeachers = Deserialization.DeserializeTeachers(path + "teachers.xml");
            deserializedPupils = Deserialization.DeserializePupils(path + "pupils.xml");
            deserializedGroup = Deserialization.DeserializeStudyGroup(path + "group.xml");
            deserializedLecture = Deserialization.DeserializeLecture(path + "lecture.xml");

            deserializedGroup.Recover(deserializedPupils);
            deserializedLecture.Recover(deserializedGroup, deserializedSubject, deserializedTeachers, deserializedPupils);

            #endregion

            // checking out

            Console.WriteLine(teachersToSerialize[0].Equals(lectureToSerialize.teacher));
            Console.WriteLine(groupToSerialize.listOfPupils[0].Equals(lectureToSerialize.studyGroup.listOfPupils[0]));

            Console.WriteLine(deserializedTeachers[0].Equals(deserializedLecture.teacher));
            Console.WriteLine(deserializedGroup.listOfPupils[0].Equals(deserializedLecture.studyGroup.listOfPupils[0]));

            // As you can see in both cases references are equal. That means we saved reference connections.

            Console.ReadKey();
        }
    }
}
