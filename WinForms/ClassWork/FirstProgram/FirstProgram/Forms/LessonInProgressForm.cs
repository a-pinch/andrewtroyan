using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace FirstProgram
{
    public partial class LessonInProgressForm : Form
    {
        XmlNode relativeTeacher;
        XmlNode currentLessonInSchedule;
        string topics;

        public LessonInProgressForm()
        {
            InitializeComponent();
        }

        public LessonInProgressForm(XmlNode relativeTeacher_, XmlNode currentLessonInSchedule_, string topics_) : this()
        {
            relativeTeacher = relativeTeacher_;
            currentLessonInSchedule = currentLessonInSchedule_;
            topics = topics_;

            this.labelDate.Text += " " + currentLessonInSchedule.SelectSingleNode("date").InnerText;
            this.labelStartTime.Text += " " + currentLessonInSchedule.SelectSingleNode("time").InnerText;

            //XmlDocument subjectsDocument = new XmlDocument();
            //subjectsDocument.Load(Data.subjectsLocation);
            //this.labelDate.Text += " " + subjectsDocument.SelectSingleNode("root/subject[@id='" + 
            //    currentLessonInSchedule.SelectSingleNode("subject").InnerText + "']/name").InnerText;
        }
    }
}
