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
            Subject csharpSubject = new Subject("C#", new List<string>(){"Serialization", "Attributes"});

            Teacher teacher = new Teacher("Maxim");

            List<Pupil> pupils = new List<Pupil>() { new Pupil("Andrew"), new Pupil("Igor"), new Pupil("Kolya"), new Pupil("Ira"), new Pupil("Andrew")
                , new Pupil("Olya"), new Pupil("Arseniy"), new Pupil("Oleg") };
            StudyGroup group = new StudyGroup("P11014", pupils);

            Lecture lecture1 = new Lecture(csharpSubject, "Serialization", teacher, group);
            teacher.GiveMark(lecture1, new Mark(10, group.listOfPupils[2], MarkGround.homework));

            //XmlSerializer subjectSerializer = new XmlSerializer(typeof(Lecture));
            //using (var file = new StreamWriter("..\\..\\subject.xml"))
            //{
            //    subjectSerializer.Serialize(file, lecture1);
            //}

            Console.ReadKey();
        }
    }
}
