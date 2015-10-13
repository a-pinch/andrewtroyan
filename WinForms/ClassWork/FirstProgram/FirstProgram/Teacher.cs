using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace FirstProgram
{
    public class Teacher : Human
    {
        private static int globalID;
        public static XmlDocument xmlDocument;

        static Teacher()
        {
            xmlDocument = new XmlDocument();
            xmlDocument.Load(Data.teachersLocation);
            XmlNode root = xmlDocument.SelectSingleNode("root");
            XmlNode lastTeacher = root.LastChild;
            if (lastTeacher != null)
            {
                var attributes = lastTeacher.Attributes;
                globalID = int.Parse(attributes[0].InnerText) + 1;
            }
            else
            {
                globalID = 0;
            }
        }

        private int currentID;
        private string login, password;

        public Teacher()
        {
            currentID = globalID++;
        }

        public Teacher(string name_, string surname_, string login_, string password_) : this()
        {
            name = name_;
            surname = surname_;
            login = login_;
            password = password_;
        }

        public void AddNewTeacher()
        {
            XmlNode root = xmlDocument.SelectSingleNode("root");
            XmlElement newTeacherNode = xmlDocument.CreateElement("teacher");
            newTeacherNode.SetAttribute("id", currentID.ToString());
            XmlElement nameNode = xmlDocument.CreateElement("name");
            nameNode.InnerText = name;
            XmlElement surnameNode = xmlDocument.CreateElement("surname");
            surnameNode.InnerText = surname;
            XmlElement loginNode = xmlDocument.CreateElement("login");
            loginNode.InnerText = login;
            XmlElement passwordNode = xmlDocument.CreateElement("password");
            passwordNode.InnerText = password;
            newTeacherNode.AppendChild(nameNode);
            newTeacherNode.AppendChild(surnameNode);
            newTeacherNode.AppendChild(loginNode);
            newTeacherNode.AppendChild(passwordNode);
            root.AppendChild(newTeacherNode);
            xmlDocument.Save(Data.teachersLocation);
        }

        //public void GiveMark(Lesson lecture, Mark mark)
        //{
        //    if (lecture.studyGroup.listOfPupils.Contains(mark.pupil) == false)
        //    {
        //        throw new InvalidOperationException("In Teacher.GiveMark(StudyGroup, Mark, Pupil): there isn't this pupil in this group.");
        //    }

        //    lecture.marks.Add(mark);
        //}
    }
}
