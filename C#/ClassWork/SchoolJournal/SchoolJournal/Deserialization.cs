using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Xml.Serialization;

namespace SchoolJournal
{
    public static class Deserialization
    {
        // static methods for deserialization

        public static List<Teacher> DeserializeTeachers(string path)
        {
            if (File.Exists(path) == false)
            {
                throw new FileNotFoundException("In Deserialization.DeserializeTeachers(string): file doesn't exist.");
            }

            List<Teacher> result;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<Teacher>));

            using (var file = new StreamReader(path))
            {
                result = (List<Teacher>)deserializer.Deserialize(file);
            }

            return result;
        }

        public static List<Pupil> DeserializePupils(string path)
        {
            if (File.Exists(path) == false)
            {
                throw new FileNotFoundException("In Deserialization.DeserializePupils(string): file doesn't exist.");
            }

            List<Pupil> result;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<Pupil>));

            using (var file = new StreamReader(path))
            {
                result = (List<Pupil>)deserializer.Deserialize(file);
            }

            return result;
        }

        public static List<StudyGroup> DeserializeStudyGroups(string path)
        {
            if (File.Exists(path) == false)
            {
                throw new FileNotFoundException("In Deserialization.DeserializeStudyGroup(string): file doesn't exist.");
            }

            List<StudyGroup> result;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<StudyGroup>));

            using (var file = new StreamReader(path))
            {
                result = (List<StudyGroup>)deserializer.Deserialize(file);
            }

            return result;
        }

        public static List<Subject> DeserializeSubjects(string path)
        {
            if (File.Exists(path) == false)
            {
                throw new FileNotFoundException("In Deserialization.DeserializeSubject(string): file doesn't exist.");
            }

            List<Subject> result;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<Subject>));

            using (var file = new StreamReader(path))
            {
                result = (List<Subject>)deserializer.Deserialize(file);
            }

            return result;
        }
        
        public static List<Lecture> DeserializeLecture(string path)
        {
            if (File.Exists(path) == false)
            {
                throw new FileNotFoundException("In Deserialization.DeserializeLecture(string): file doesn't exist.");
            }

            List<Lecture> result;
            XmlSerializer deserializer = new XmlSerializer(typeof(List<Lecture>));

            using (var file = new StreamReader(path))
            {
                result = (List<Lecture>)deserializer.Deserialize(file);
            }

            return result;
        }
    }
}
