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
                MessageBox.Show("You didn't fill all fields!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                var existingLogins = Teacher.xmlDocument.SelectSingleNode("root/teacher[login='" +
                    this.textBoxForLogin.Text + "']");

                if (existingLogins == null)
                {
                    MessageBox.Show("This user doesn't exist!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    var existingTeacher = Teacher.xmlDocument.SelectSingleNode("root/teacher[login='" + this.textBoxForLogin.Text + "' and password='"
                        + this.textBoxForPassword.Text.GetHashCode() + "']");

                    if (existingTeacher == null)
                    {
                        MessageBox.Show("Wrong password!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    }
                    else
                    {
                        new ExistingUserPageForm(this, existingTeacher).Show();
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
            this.textBoxForLogin.Clear();
            this.textBoxForPassword.Clear();
        }

        private void textBoxForPassword_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyValue == 13)
            {
                this.buttonEnter_Click(null, null);
            }  
        }
    }
}
