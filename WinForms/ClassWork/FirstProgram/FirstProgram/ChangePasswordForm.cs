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
    public partial class ChangePasswordForm : Form
    {
        XmlDocument xmlDocument;
        XmlNode relativeTeacher;

        public ChangePasswordForm()
        {
            InitializeComponent();
        }

        public ChangePasswordForm(XmlDocument xmlDocument_, XmlNode relativeTeacher_) : this()
        {
            xmlDocument = xmlDocument_;
            relativeTeacher = relativeTeacher_;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.textBox1.Text.Any() == false || this.textBox2.Text.Any() == false)
            {
                MessageBox.Show("You didn't fill all fields!", "Error", MessageBoxButtons.OK);
            }
            else if (this.textBox1.Text.GetHashCode().ToString() != relativeTeacher.SelectSingleNode("password").InnerText)
            {
                MessageBox.Show("You entered wrong old password!", "Error", MessageBoxButtons.OK);
            }
            else
            {
                relativeTeacher.SelectSingleNode("password").InnerText = this.textBox2.Text.GetHashCode().ToString();
                xmlDocument.Save("..\\..\\users.xml");
                MessageBox.Show("Your password was successfully changed!", "Success", MessageBoxButtons.OK);
                this.Close();
            }
        }
    }
}
