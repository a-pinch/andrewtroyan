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

        string[] absentOrPresent;
        List<int> absents;
        List<Mark> marks;

        public LessonInProgressForm()
        {
            InitializeComponent();
        }

        public LessonInProgressForm(XmlNode relativeTeacher_, XmlNode currentLessonInSchedule_, string topics_) : this()
        {
            relativeTeacher = relativeTeacher_;
            currentLessonInSchedule = currentLessonInSchedule_;
            topics = topics_;

            absentOrPresent = new string[]{ "a", "p" };
            absents = new List<int>();
            marks = new List<Mark>();

            this.labelDate.Text += " " + currentLessonInSchedule.SelectSingleNode("date").InnerText;
            this.labelStartTime.Text += " " + currentLessonInSchedule.SelectSingleNode("time").InnerText;
            this.labelStartTime.Location = new Point(this.labelDate.Location.X + this.labelDate.Size.Width + 10, 
                this.labelDate.Location.Y);

            this.labelGroup.Text += " " + Group.xmlDocument.SelectSingleNode("root/group[@id='" + 
                currentLessonInSchedule.SelectSingleNode("group").InnerText + "']/name").InnerText;
            this.labelTeacher.Text += " " + relativeTeacher.SelectSingleNode("name").InnerText + " " + 
                relativeTeacher.SelectSingleNode("surname").InnerText;
            this.labelTeacher.Location = new Point(this.labelGroup.Location.X + this.labelGroup.Size.Width + 10,
                this.labelGroup.Location.Y);

            this.labelSubject.Text += " " + Subject.xmlDocument.SelectSingleNode("root/subject[@id='" +
                currentLessonInSchedule.SelectSingleNode("subject").InnerText + "']/name").InnerText;
            this.labelTopics.Text += " " + topics;
            this.labelTopics.Location = new Point(this.labelSubject.Location.X + this.labelSubject.Size.Width + 10,
                this.labelSubject.Location.Y);

            XmlNodeList pupilIds = Group.xmlDocument.SelectNodes("root/group[@id='" + currentLessonInSchedule.SelectSingleNode("group").InnerText + "']/pupils/id");
            this.tableWithLessonInfo.RowStyles[0] = new RowStyle(SizeType.Absolute, 20f);
            this.tableWithLessonInfo.Height = this.ClientRectangle.Height - this.tableWithLessonInfo.Location.X - this.tableWithLessonInfo.Location.Y;

            foreach (XmlNode pupilId in pupilIds)
            {
                this.tableWithLessonInfo.RowCount += 1;
                this.tableWithLessonInfo.RowStyles.Add(new RowStyle(SizeType.Percent, 100f / pupilIds.Count));
                XmlNode pupil = Pupil.xmlDocument.SelectSingleNode("root/pupil[@id='" + pupilId.InnerText + "']");
                this.tableWithLessonInfo.Controls.Add(new Label() {
                    Text = pupil.SelectSingleNode("name").InnerText + " " + pupil.SelectSingleNode("surname").InnerText,
                    Dock = DockStyle.Fill,
                    TextAlign = ContentAlignment.MiddleCenter,
                    AutoSize = true
                }, 0, this.tableWithLessonInfo.RowCount - 1);
            }
        }
    }
}
