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
    public partial class StartLessonForm : Form
    {
        XmlDocument xmlDocument;
        XmlNode relativeTeacher;

        XmlNode necessaryLesson;
        TextBox textBoxWithTopics;

        public StartLessonForm()
        {
            InitializeComponent();
        }

        public StartLessonForm(XmlDocument xmlDocument_, XmlNode relativeTeacher_) : this()
        {
            xmlDocument = xmlDocument_;
            relativeTeacher = relativeTeacher_;
            this.comboBoxWithScheduleTime.Items.AddRange(Data.time);
            var test = this.comboBoxWithScheduleTime.SelectedIndex;
            this.buttonStartLesson.Hide();
        }

        private void comboBoxWithScheduleTime_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = comboBoxWithScheduleTime.SelectedIndex;

            this.Controls.RemoveByKey("noLessonsLabel");
            this.Controls.RemoveByKey("subjectNameLabel");
            this.Controls.RemoveByKey("groupNameLabel");
            this.Controls.RemoveByKey("topicLabel");
            this.Controls.RemoveByKey("textBoxWithTopics");

            if (index != -1)
            {
                string selectedTime = Data.time[index];
                string selectedDate = this.dateTimePickerForLesson.Value.ToString().Split(new char[] { ' ' })[0];

                XmlDocument scheduleLessons = new XmlDocument();
                scheduleLessons.Load(Data.scheduleLocation);
                necessaryLesson = scheduleLessons.SelectSingleNode("root/scheduleDay/lesson[date='" + selectedDate
                    + "' and time='" + selectedTime + "' and teacher='" + relativeTeacher.Attributes[0].Value + "']");

                if (necessaryLesson == null)
                {
                    Label noLessonsLabel = new Label()
                    {
                        Name = "noLessonsLabel",
                        Text = "No lessons in schedule!",
                        AutoSize = true,
                        Location =
                            new Point(this.labelSelectTime.Location.X, this.labelSelectTime.Location.Y + this.labelSelectTime.Size.Height + 20)
                    };
                    this.Controls.Add(noLessonsLabel);
                }
                else
                {
                    XmlDocument subjectsDocument = new XmlDocument();
                    subjectsDocument.Load(Data.subjectsLocation);
                    string subjectName = subjectsDocument.SelectSingleNode("root/subject[@id='" + necessaryLesson.SelectSingleNode("subject").InnerText
                        + "']/name").InnerText;

                    XmlDocument groupDocument = new XmlDocument();
                    groupDocument.Load(Data.groupsLocation);
                    string groupName = groupDocument.SelectSingleNode("root/group[@id='" + necessaryLesson.SelectSingleNode("group").InnerText +
                        "']/name").InnerText;

                    Label subjectNameLabel = new Label()
                    {
                        Name = "subjectNameLabel",
                        Text = "Subject: " + subjectName,
                        AutoSize = true,
                        Location = new Point(this.labelSelectTime.Location.X, this.labelSelectTime.Location.Y + this.labelSelectTime.Size.Height + 20)
                    };
                    this.Controls.Add(subjectNameLabel);

                    Label groupNameLabel = new Label()
                    {
                        Name = "groupNameLabel",
                        Text = "Group: " + groupName,
                        AutoSize = true,
                        Location = new Point(subjectNameLabel.Location.X + subjectNameLabel.Size.Width + 10, subjectNameLabel.Location.Y)
                    };
                    this.Controls.Add(groupNameLabel);

                    Label topicLabel = new Label()
                    {
                        Name = "topicLabel",
                        Text = "Topic(s):",
                        AutoSize = true,
                        Location =
                            new Point(subjectNameLabel.Location.X, subjectNameLabel.Location.Y + subjectNameLabel.Size.Height + 15)
                    };
                    this.Controls.Add(topicLabel);

                    textBoxWithTopics = new TextBox()
                    {
                        Name = "textBoxWithTopics",
                        Location = new Point(topicLabel.Location.X +
                            topicLabel.Size.Width + 10, topicLabel.Location.Y - 2)
                    };
                    textBoxWithTopics.Width = dateTimePickerForLesson.Location.X + dateTimePickerForLesson.Size.Width - textBoxWithTopics.Location.X;

                    var topics = necessaryLesson.SelectNodes("topics/topic");
                    textBoxWithTopics.Text = topics[0].InnerText;
                    for (int i = 1; i < topics.Count; ++i)
                    {
                        textBoxWithTopics.Text += ", " + topics[i].InnerText;
                    }

                    this.Controls.Add(textBoxWithTopics);
                    this.buttonStartLesson.Show();
                }
            }
        }

        private void buttonStartLesson_Click(object sender, EventArgs e)
        {
            new LessonInProgressForm(relativeTeacher, necessaryLesson, textBoxWithTopics.Text).Show();
        }

        private void dateTimePickerForLesson_ValueChanged(object sender, EventArgs e)
        {
            this.comboBoxWithScheduleTime.SelectedIndex = -1;
        }
    }
}
