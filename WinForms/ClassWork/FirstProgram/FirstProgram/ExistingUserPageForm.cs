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
    public partial class ExistingUserPageForm : Form
    {
        Form1 parent;
        XmlDocument xmlDocument;
        XmlNode relativeTeacher;
        System.Windows.Forms.Timer timer = null;

        public ExistingUserPageForm()
        {
            InitializeComponent();
        }

        public ExistingUserPageForm(Form1 parent_, XmlDocument xmlDocument_, XmlNode relativeTeacher_) : this()
        {
            parent = parent_;
            xmlDocument = xmlDocument_;
            relativeTeacher = relativeTeacher_;
            this.Text = "Welcome, " + relativeTeacher.SelectSingleNode("name").InnerText + " " + 
                relativeTeacher.SelectSingleNode("surname").InnerText + "!";

            labelDate.Text = DateTime.Now.ToString();

            timer = new Timer();
            timer.Interval = 1000;
            timer.Tick += new EventHandler(timerTick);
            timer.Enabled = true;
        }
        private void timerTick(object sender, EventArgs e)
        {
            labelDate.Text = DateTime.Now.ToString();
        }

        private void buttonChangePassword_Click(object sender, EventArgs e)
        {
            new ChangePasswordForm(xmlDocument, relativeTeacher).ShowDialog();
        }

        private void ExistingUserPageForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            parent.Show();
        }

        private void buttonLogOut_Click(object sender, EventArgs e)
        {
            var answer = MessageBox.Show("Are you sure?", "Exit", MessageBoxButtons.YesNo);
            if (answer == System.Windows.Forms.DialogResult.Yes)
            {
                this.Close();
            }
        }
    }
}
