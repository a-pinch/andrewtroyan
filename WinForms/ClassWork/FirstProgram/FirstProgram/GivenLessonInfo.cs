using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace FirstProgram
{
    public partial class GivenLessonInfo : UserControl
    {
        XmlNode lesson;

        public GivenLessonInfo()
        {
            InitializeComponent();
        }

        public GivenLessonInfo(XmlNode lesson_) : this()
        {
            lesson = lesson_;

            XmlDocument subjectsDocument = new XmlDocument();
            subjectsDocument.Load(Data.subjectsLocation);
            string subjectName = subjectsDocument.SelectSingleNode("root/subject[@id='" +
               lesson.SelectSingleNode("subject").InnerText + "']/name" ).InnerText;
            this.labelSubjectName.Text += " " + subjectName;

            XmlNodeList topics = lesson.SelectNodes("topics/topic");
            this.labelTopics.Text += " " + topics[0].InnerText;

            for (int i = 1; i < topics.Count; ++i)
            {
                this.labelTopics.Text += ", " + topics[0].InnerText;
            }

            XmlDocument pupilsDocument = new XmlDocument();
            pupilsDocument.Load(Data.pupilsLocation);

            XmlDocument groupsDocument = new XmlDocument();
            groupsDocument.Load(Data.groupsLocation);

            foreach (XmlNode pupilId in groupsDocument.SelectNodes("root/group[@id='" +
                lesson.SelectSingleNode("group").InnerText + "']/pupils/id"))
            {
                Label labelWithName = new Label();
                labelWithName.Dock = DockStyle.Fill;
                XmlNode pupil = pupilsDocument.SelectSingleNode("root/pupil[@id='" + pupilId.InnerText + "']");
                labelWithName.Text = pupil.SelectSingleNode("name").InnerText +
                    " " + pupil.SelectSingleNode("surname").InnerText;

                this.tableWithLessonData.RowStyles.Add(new RowStyle(SizeType.AutoSize));
                this.tableWithLessonData.Controls.Add(labelWithName, 0, this.tableWithLessonData.RowCount - 1);
            }
        }
    }
}
