using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace SchoolJournal
{
    public static class Serialization
    {
        // extension methods for serializtion

        public static void Serialize(this List<Teacher> teachers, string path)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Teacher>));

            using (var file = new StreamWriter(path))
            {
                serializer.Serialize(file, teachers);
            }
        }

        public static void Serialize(this List<Pupil> pupils, string path)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Pupil>));

            using (var file = new StreamWriter(path))
            {
                serializer.Serialize(file, pupils);
            }
        }

        public static void Serialize(this List<StudyGroup> groups, string path)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<StudyGroup>));

            using (var file = new StreamWriter(path))
            {
                serializer.Serialize(file, groups);
            }
        }

        public static void Serialize(this List<Subject> subjects, string path)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(List<Subject>));

            using (var file = new StreamWriter(path))
            {
                serializer.Serialize(file, subjects);
            }
        }

        public static void Serialize(this Lecture lecture, string path)
        {
            XmlSerializer serializer = new XmlSerializer(typeof(Lecture));

            using (var file = new StreamWriter(path))
            {
                serializer.Serialize(file, lecture);
            }
        }
    }
}
