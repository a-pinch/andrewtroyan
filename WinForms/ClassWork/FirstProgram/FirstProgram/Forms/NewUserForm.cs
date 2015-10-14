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
    public partial class NewUserForm : Form
    {
        public NewUserForm()
        {
            InitializeComponent();
        }

        private void buttonRegister_Click(object sender, EventArgs e)
        {
            if (this.textBoxForLogin.Text.Any() == false || this.textBoxForName.Text.Any() == false ||
                this.textBoxForSurname.Text.Any() == false || this.textBoxForPassword.Text.Any() == false)
            {
                MessageBox.Show("You didn't fill all fields!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            else
            {
                XmlNode root = Teacher.xmlDocument.SelectSingleNode("root");

                var existing = root.SelectSingleNode("teacher[login='" + this.textBoxForLogin.Text + "' and password='" 
                    + this.textBoxForPassword.Text.GetHashCode() + "']");

                if (existing != null)
                {
                    MessageBox.Show("This users already exists!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                }
                else
                {
                    var newTeacher = new Teacher(textBoxForName.Text, textBoxForSurname.Text, 
                        textBoxForLogin.Text, textBoxForPassword.Text.GetHashCode().ToString());
                    newTeacher.AddToXml();
                    MessageBox.Show("This user has been successfully created!", "Success", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
                    this.Close();
                }
            }
        }
    }
}
