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
            List<Lecture> lecturesToSerialize, deserializedLectures;

            #region Lecturing imitation

            subjectsToSerialize = new List<Subject>() { new Subject("C#", new List<string>() { "Serialization", "Attributes", "XML", "XSLT" }) };

            teachersToSerialize = new List<Teacher>() { new Teacher("Maxim", "Belov"), new Teacher("Alexey", "Stankevich") };

            pupilsToSerialize = new List<Pupil>() { new Pupil("Andrew", "Troyan"), new Pupil("Igor", "Saroko"), new Pupil("Kolya", "Morschinin"),
                new Pupil("Ira", "Lesina"), new Pupil("Andrew", "Pinchuk"), new Pupil("Olya", "Pirozhnik"), new Pupil("Arseniy", "Vinogradov"), new Pupil("Oleg", "Grebenko") };

            groupsToSerialize = new List<StudyGroup>() { new StudyGroup("P11014", pupilsToSerialize) };

            lecturesToSerialize = new List<Lecture>() { new Lecture(new DateTime(2015, 09, 23), subjectsToSerialize[0], new List<string>() { "Serialization", "Attributes" }, teachersToSerialize[0], groupsToSerialize[0]) };
            
            teachersToSerialize[0].GiveMark(lecturesToSerialize[0], new Mark(9, groupsToSerialize[0].listOfPupils[2], teachersToSerialize[0], MarkGround.homework));
            teachersToSerialize[0].GiveMark(lecturesToSerialize[0], new Mark(10, groupsToSerialize[0].listOfPupils[2], teachersToSerialize[0], MarkGround.controlwork));
            teachersToSerialize[0].GiveMark(lecturesToSerialize[0], new Mark(10, groupsToSerialize[0].listOfPupils[3], teachersToSerialize[0], MarkGround.board));
            teachersToSerialize[0].GiveMark(lecturesToSerialize[0], new Mark(10, groupsToSerialize[0].listOfPupils[6], teachersToSerialize[0], MarkGround.homework));
            teachersToSerialize[0].GiveMark(lecturesToSerialize[0], new Mark(10, groupsToSerialize[0].listOfPupils[7], teachersToSerialize[0], MarkGround.homework));

            Lecture lecture2 = new Lecture(new DateTime(2015, 09, 29), subjectsToSerialize[0], new List<string>() { "XML" }, teachersToSerialize[0], groupsToSerialize[0]);
            lecturesToSerialize.Add(lecture2);

            teachersToSerialize[0].GiveMark(lecture2, new Mark(10, groupsToSerialize[0].listOfPupils[1], teachersToSerialize[0], MarkGround.homework));
            teachersToSerialize[0].GiveMark(lecture2, new Mark(10, groupsToSerialize[0].listOfPupils[0], teachersToSerialize[0], MarkGround.controlwork));
            teachersToSerialize[0].GiveMark(lecture2, new Mark(10, groupsToSerialize[0].listOfPupils[6], teachersToSerialize[0], MarkGround.board));
            teachersToSerialize[0].GiveMark(lecture2, new Mark(10, groupsToSerialize[0].listOfPupils[5], teachersToSerialize[0], MarkGround.controlwork));
            teachersToSerialize[0].GiveMark(lecture2, new Mark(10, groupsToSerialize[0].listOfPupils[4], teachersToSerialize[0], MarkGround.board));

            #endregion

            #region Serialization

            subjectsToSerialize.Serialize(path + "subjects.xml");
            teachersToSerialize.Serialize(path + "teachers.xml");
            pupilsToSerialize.Serialize(path + "pupils.xml");
            groupsToSerialize.Serialize(path + "groups.xml");
            lecturesToSerialize.Serialize(path + "lectures.xml");

            #endregion 

            #region Deserialization and connections recovering

            deserializedSubjects = Deserialization.DeserializeSubjects(path + "subjects.xml");
            deserializedTeachers = Deserialization.DeserializeTeachers(path + "teachers.xml");
            deserializedPupils = Deserialization.DeserializePupils(path + "pupils.xml");
            deserializedGroups = Deserialization.DeserializeStudyGroups(path + "groups.xml");
            deserializedLectures = Deserialization.DeserializeLecture(path + "lectures.xml");

            deserializedGroups.Recover(deserializedPupils);
            deserializedLectures.Recover(deserializedGroups, deserializedSubjects, deserializedTeachers, deserializedPupils);

            #endregion

            // checking out

            Console.WriteLine(teachersToSerialize[0].Equals(lecturesToSerialize[0].teacher));
            Console.WriteLine(groupsToSerialize[0].listOfPupils[0].Equals(lecturesToSerialize[0].studyGroup.listOfPupils[0]));

            Console.WriteLine(deserializedTeachers[0].Equals(deserializedLectures[0].teacher));
            Console.WriteLine(deserializedGroups[0].listOfPupils[0].Equals(deserializedLectures[0].studyGroup.listOfPupils[0]));

            // As you can see in both cases references are equal. That means we saved reference connections.

            Console.ReadKey();
        }
    }
}
