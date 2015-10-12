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

        public ExistingUserPageForm()
        {
            InitializeComponent();
        }

        public ExistingUserPageForm(Form1 parent_, XmlDocument xmlDocument_, XmlNode relativeTeacher_) : this()
        {
            parent = parent_;
            xmlDocument = xmlDocument_;
            relativeTeacher = relativeTeacher_;
            this.Text = "Welcome, " + relativeTeacher.SelectSingleNode("fullName").InnerText + "!";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            new ChangePasswordForm(xmlDocument, relativeTeacher).Show();
        }

        private void ExistingUserPageForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            parent.Close();
        }
    }
}
