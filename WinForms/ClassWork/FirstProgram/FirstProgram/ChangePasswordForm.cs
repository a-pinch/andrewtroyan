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

        private void buttonChangePassword_Click(object sender, EventArgs e)
        {
            if (this.textBoxForOldPassword.Text.Any() == false || this.textBoxForNewPassword.Text.Any() == false)
            {
                MessageBox.Show("You didn't fill all fields!", "Error", MessageBoxButtons.OK);
            }
            else if (this.textBoxForOldPassword.Text.GetHashCode().ToString() != relativeTeacher.SelectSingleNode("password").InnerText)
            {
                MessageBox.Show("You entered wrong old password!", "Error", MessageBoxButtons.OK);
            }
            else
            {
                relativeTeacher.SelectSingleNode("password").InnerText = this.textBoxForNewPassword.Text.GetHashCode().ToString();
                xmlDocument.Save(Data.teachersLocation);
                MessageBox.Show("Your password was successfully changed!", "Success", MessageBoxButtons.OK);
                this.Close();
            }
        }
    }
}
