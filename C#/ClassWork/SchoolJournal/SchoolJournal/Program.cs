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
            List<Subject> subjectsToSerialize, deserializedSubjects;
            List<Teacher> teachersToSerialize, deserializedTeachers;
            List<Pupil> pupilsToSerialize, deserializedPupils;
            List<StudyGroup> groupsToSerialize, deserializedGroups;
            Lecture lectureToSerialize, deserializedLecture;

            #region Lecturing imitation

            subjectsToSerialize = new List<Subject>() { new Subject("C#", new List<string>() { "Serialization", "Attributes" }) };

            teachersToSerialize = new List<Teacher>() { new Teacher("Maxim", "Belov"), new Teacher("Alexey", "Stankevich") };

            pupilsToSerialize = new List<Pupil>() { new Pupil("Andrew", "Troyan"), new Pupil("Igor", "Saroko"), new Pupil("Kolya", "Morschinin"),
                new Pupil("Ira", "Lesina"), new Pupil("Andrew", "Pinchuk"), new Pupil("Olya", "Pirozhnik"), new Pupil("Arseniy", "Vinogradov"), new Pupil("Oleg", "Grebenko") };

            groupsToSerialize = new List<StudyGroup>() { new StudyGroup("P11014", pupilsToSerialize) };

            lectureToSerialize = new Lecture(subjectsToSerialize[0], "Serialization", teachersToSerialize[0], groupsToSerialize[0]);

            teachersToSerialize[0].GiveMark(lectureToSerialize, new Mark(10, groupsToSerialize[0].listOfPupils[2], teachersToSerialize[0], MarkGround.homework));
            teachersToSerialize[0].GiveMark(lectureToSerialize, new Mark(10, groupsToSerialize[0].listOfPupils[3], teachersToSerialize[0], MarkGround.board));

            #endregion

            #region Serialization

            subjectsToSerialize.Serialize(path + "subjects.xml");
            teachersToSerialize.Serialize(path + "teachers.xml");
            pupilsToSerialize.Serialize(path + "pupils.xml");
            groupsToSerialize.Serialize(path + "groups.xml");
            lectureToSerialize.Serialize(path + "lecture.xml");

            #endregion 

            #region Deserialization and connections recovering

            deserializedSubjects = Deserialization.DeserializeSubjects(path + "subjects.xml");
            deserializedTeachers = Deserialization.DeserializeTeachers(path + "teachers.xml");
            deserializedPupils = Deserialization.DeserializePupils(path + "pupils.xml");
            deserializedGroups = Deserialization.DeserializeStudyGroups(path + "groups.xml");
            deserializedLecture = Deserialization.DeserializeLecture(path + "lecture.xml");

            deserializedGroups.Recover(deserializedPupils);
            deserializedLecture.Recover(deserializedGroups, deserializedSubjects, deserializedTeachers, deserializedPupils);

            #endregion

            // checking out

            Console.WriteLine(teachersToSerialize[0].Equals(lectureToSerialize.teacher));
            Console.WriteLine(groupsToSerialize[0].listOfPupils[0].Equals(lectureToSerialize.studyGroup.listOfPupils[0]));

            Console.WriteLine(deserializedTeachers[0].Equals(deserializedLecture.teacher));
            Console.WriteLine(deserializedGroups[0].listOfPupils[0].Equals(deserializedLecture.studyGroup.listOfPupils[0]));

            // As you can see in both cases references are equal. That means we saved reference connections.

            Console.ReadKey();
        }
    }
}
