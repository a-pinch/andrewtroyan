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
        XmlNode relativeTeacher;
        XmlNode necessaryLesson;

        public StartLessonForm()
        {
            InitializeComponent();
        }

        public StartLessonForm(XmlNode relativeTeacher_) : this()
        {
            relativeTeacher = relativeTeacher_;
            this.comboBoxWithScheduleTime.Items.AddRange(Data.time);
            var test = this.comboBoxWithScheduleTime.SelectedIndex;

            this.buttonStartLesson.Hide();
            this.labelWithSubjectName.Hide();
            this.labelWithGroupName.Hide();
            this.labelWithTopics.Hide();
            this.textBoxWithTopicNames.Hide();
        }

        private void comboBoxWithScheduleTime_SelectedIndexChanged(object sender, EventArgs e)
        {
            int index = comboBoxWithScheduleTime.SelectedIndex;

            this.buttonStartLesson.Hide();
            this.labelWithSubjectName.Hide();
            this.labelWithGroupName.Hide();
            this.labelWithTopics.Hide();
            this.textBoxWithTopicNames.Hide();

            if (index != -1)
            {
                string selectedTime = Data.time[index];
                string selectedDate = this.dateTimePickerForLesson.Value.ToString().Split(new char[] { ' ' })[0];
                
                necessaryLesson = Schedule.xmlDocument.SelectSingleNode("root/scheduleDay/lesson[date='" + selectedDate
                    + "' and time='" + selectedTime + "' and teacher='" + relativeTeacher.Attributes[0].Value + "']");

                if (necessaryLesson == null)
                {
                    this.labelWithSubjectName.Text = "No lessons in schedule!";
                    this.labelWithSubjectName.Show();
                }
                else
                {
                    this.labelWithSubjectName.Text = "Subject: " + Subject.xmlDocument.SelectSingleNode("root/subject[@id='" + 
                        necessaryLesson.SelectSingleNode("subject").InnerText + "']/name").InnerText;
                    this.labelWithSubjectName.Show();

                    this.labelWithGroupName.Text = "Group: " + Group.xmlDocument.SelectSingleNode("root/group[@id='" + 
                        necessaryLesson.SelectSingleNode("group").InnerText + "']/name").InnerText;
                    this.labelWithGroupName.Location = new Point(this.labelWithSubjectName.Location.X + 
                        this.labelWithSubjectName.Size.Width + 10, this.labelWithSubjectName.Location.Y);
                    this.labelWithGroupName.Show();

                    this.labelWithTopics.Show();

                    this.textBoxWithTopicNames.Location = new Point(this.labelWithTopics.Location.X + this.labelWithTopics.Size.Width +
                        10, this.labelWithTopics.Location.Y - 2);
                    this.textBoxWithTopicNames.Width = dateTimePickerForLesson.Location.X + dateTimePickerForLesson.Size.Width - this.textBoxWithTopicNames.Location.X;

                    var topics = necessaryLesson.SelectNodes("topics/topic");
                    this.textBoxWithTopicNames.Text = topics[0].InnerText;
                    for (int i = 1; i < topics.Count; ++i)
                    {
                        this.textBoxWithTopicNames.Text += ", " + topics[i].InnerText;
                    }

                    this.textBoxWithTopicNames.Show();
                    this.buttonStartLesson.Show();
                }
            }
        }

        private void buttonStartLesson_Click(object sender, EventArgs e)
        {
            new LessonInProgressForm(relativeTeacher, necessaryLesson, this.textBoxWithTopicNames.Text).Show();
        }

        private void dateTimePickerForLesson_ValueChanged(object sender, EventArgs e)
        {
            this.comboBoxWithScheduleTime.SelectedIndex = -1;
        }
    }
}
