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
    public partial class WatchGivenLessonsForm : Form
    {
        XmlNode relativeTeacher;
        XmlNodeList givenLessons;

        public WatchGivenLessonsForm()
        {
            InitializeComponent();
        }

        public WatchGivenLessonsForm(XmlNode relativeTeacher_) : this()
        {
            relativeTeacher = relativeTeacher_;

            this.labelWithGroupName.Hide();
            this.labelWithSubjectName.Hide();
            this.labelWithTopics.Hide();

            givenLessons = Lesson.xmlDocument.SelectNodes("root/lesson[teacher='" + 
                relativeTeacher.Attributes[0].Value + "']");

            foreach (XmlNode lesson in givenLessons)
            {
                this.comboBoxWithGivenLessonsDates.Items.Add(lesson.SelectSingleNode("date").InnerText +
                    " " + lesson.SelectSingleNode("time").InnerText);
            }
        }

        private void comboBoxWithGivenLessonsDates_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = this.comboBoxWithGivenLessonsDates.SelectedIndex;
            XmlNode selectedLesson = givenLessons[index];

            this.labelWithGroupName.Show();
            this.labelWithSubjectName.Show();
            this.labelWithTopics.Show();
            this.Controls.RemoveByKey("tableWithLessonData");
            
            labelWithSubjectName.Text = "Subject: " + Subject.xmlDocument.SelectSingleNode(
                "root/subject[@id='" + selectedLesson.SelectSingleNode("subject").InnerText + "']/name").InnerText;
            labelWithSubjectName.Location = new Point(LabelSelectDate.Location.X, LabelSelectDate.Location.Y
                + LabelSelectDate.Size.Height + 15);

            XmlNodeList topics = selectedLesson.SelectNodes("topics/topic");
            labelWithTopics.Text = "Topic(s): " + topics[0].InnerText;
            for (int i = 1; i < topics.Count; ++i)
            {
                labelWithTopics.Text += ", " + topics[i].InnerText;
            }
            labelWithTopics.Location = new Point(labelWithSubjectName.Location.X + labelWithSubjectName.Size.Width + 10
                , labelWithSubjectName.Location.Y);
            
            labelWithGroupName.Text = "Group: " + Group.xmlDocument.SelectSingleNode("root/group[@id='" +
                selectedLesson.SelectSingleNode("group").InnerText + "']/name").InnerText;
            labelWithGroupName.Location = new Point(labelWithTopics.Location.X + labelWithTopics.Size.Width + 10
                , labelWithTopics.Location.Y);

            TableLayoutPanel tableWithLessonData = new TableLayoutPanel() {
                Name = "tableWithLessonData",
                ColumnCount = 3,
                RowCount = 1,
                CellBorderStyle = TableLayoutPanelCellBorderStyle.Single,
                Anchor = AnchorStyles.Left | AnchorStyles.Right | AnchorStyles.Bottom | AnchorStyles.Top,
                Location = new Point(this.LabelSelectDate.Location.X, labelWithSubjectName.Location.Y +
                    labelWithSubjectName.Size.Height + 10)
            };
            tableWithLessonData.Size = new Size(this.ClientRectangle.Width - labelWithSubjectName.Location.X * 2,
                this.ClientRectangle.Height - tableWithLessonData.Location.Y - tableWithLessonData.Location.X);

            tableWithLessonData.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 20f));
            tableWithLessonData.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 15f));
            tableWithLessonData.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 65f));
            tableWithLessonData.RowStyles.Add(new RowStyle(SizeType.Absolute, 30f));
            tableWithLessonData.Controls.Add(new Label() { Text = "Pupil", AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill }, 0, 0);
            tableWithLessonData.Controls.Add(new Label() { Text = "Presence", AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill }, 1, 0);
            tableWithLessonData.Controls.Add(new Label() { Text = "Marks", AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill }, 2, 0);

            // add pupils

            XmlNode pupilIds = Group.xmlDocument.SelectSingleNode("root/group[@id='" +
                selectedLesson.SelectSingleNode("group").InnerText + "']/pupils");
            int amountOfPupils = pupilIds.ChildNodes.Count;

            foreach (XmlNode pupilId in pupilIds.SelectNodes("id"))
            {
                tableWithLessonData.RowCount += 1;
                tableWithLessonData.RowStyles.Add(new RowStyle(SizeType.Percent, 100f / amountOfPupils));

                Label labelWithName = new Label() { AutoSize = true, TextAlign = ContentAlignment.MiddleCenter, Dock = DockStyle.Fill };
                XmlNode pupil = Pupil.xmlDocument.SelectSingleNode("root/pupil[@id='" + pupilId.InnerText + "']");
                labelWithName.Text = pupil.SelectSingleNode("name").InnerText +
                    " " + pupil.SelectSingleNode("surname").InnerText;
                tableWithLessonData.Controls.Add(labelWithName, 0, tableWithLessonData.RowCount - 1);

                var wasAbsent = selectedLesson.SelectSingleNode("absent[pupil='" + pupilId.InnerText + "']");
                tableWithLessonData.Controls.Add(new Label() { AutoSize = true, TextAlign = ContentAlignment.MiddleCenter,
                    Dock = DockStyle.Fill, Text = wasAbsent == null? "p" : "a" }, 1, tableWithLessonData.RowCount - 1);

                XmlNodeList marks = selectedLesson.SelectNodes("marks/mark[pupil='" + pupilId.InnerText + "']");

                if (marks.Count > 0)
                {
                    Label labelWithMarks = new Label() { AutoSize = true, TextAlign = ContentAlignment.MiddleLeft, Dock = DockStyle.Fill };
                    labelWithMarks.Text = marks[0].SelectSingleNode("point").InnerText + " (" + marks[0].SelectSingleNode("ground").InnerText + ")";

                    for (int i = 1; i < marks.Count; ++i)
                    {
                        labelWithMarks.Text += ", " + marks[i].SelectSingleNode("point").InnerText + " (" + marks[i].SelectSingleNode("ground").InnerText + ")";
                    }

                    tableWithLessonData.Controls.Add(labelWithMarks, 2, tableWithLessonData.RowCount - 1);
                }
            }

            this.Controls.Add(tableWithLessonData);
        }
    }
}
