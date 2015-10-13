using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace FirstProgram
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void buttonEnter_Click(object sender, EventArgs e)
        {
            if (this.textBoxForLogin.Text.Any() == false || this.textBoxForPassword.Text.Any() == false)
            {
                MessageBox.Show("You didn't fill all fields!", "Error", MessageBoxButtons.OK);
            }
            else
            {
                XmlDocument xmlDocument = new XmlDocument();
                xmlDocument.Load(Data.teachersLocation);

                var existingLogins = xmlDocument.SelectSingleNode("root/teacher[login='" +
                    this.textBoxForLogin.Text + "']");

                if (existingLogins == null)
                {
                    MessageBox.Show("This user doesn't exist!", "Error", MessageBoxButtons.OK);
                }
                else
                {
                    var existingTeacher = xmlDocument.SelectSingleNode("root/teacher[login='" + this.textBoxForLogin.Text + "' and password='"
                        + this.textBoxForPassword.Text.GetHashCode() + "']");

                    if (existingTeacher == null)
                    {
                        MessageBox.Show("Wrong password!", "Error", MessageBoxButtons.OK);
                    }
                    else
                    {
                        new ExistingUserPageForm(this, xmlDocument, existingTeacher).Show();
                        this.textBoxForLogin.Clear();
                        this.textBoxForPassword.Clear();
                        this.Hide();
                    }
                }
            }
        }

        private void buttonNewUser_Click(object sender, EventArgs e)
        {
            new NewUserForm().ShowDialog();
        }
    }
}
