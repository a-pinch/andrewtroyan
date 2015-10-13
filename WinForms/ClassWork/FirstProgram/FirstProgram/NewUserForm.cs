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

        private void button1_Click(object sender, EventArgs e)
        {
            if (this.textBox1.Text.Any() == false || this.textBox2.Text.Any() == false ||
                this.textBox3.Text.Any() == false)
            {
                MessageBox.Show("You didn't fill all fields!", "Error", MessageBoxButtons.OK);
            }
            else
            {
                XmlDocument xmlDocument = new XmlDocument();
                xmlDocument.Load("..\\..\\users.xml");
                XmlNode root = xmlDocument.SelectSingleNode("root");

                var existing = root.SelectSingleNode("teacher[login='" + this.textBox1.Text + "' and password='" 
                    + this.textBox3.Text.GetHashCode() + "']");

                if (existing != null)
                {
                    MessageBox.Show("This users already exists!", "Error", MessageBoxButtons.OK);
                }
                else
                {
                    XmlElement teacher = xmlDocument.CreateElement("teacher");
                    XmlElement login = xmlDocument.CreateElement("login");
                    login.InnerText = this.textBox1.Text;
                    XmlElement fullName = xmlDocument.CreateElement("fullName");
                    fullName.InnerText = this.textBox2.Text;
                    XmlElement password = xmlDocument.CreateElement("password");
                    password.InnerText = this.textBox3.Text.GetHashCode().ToString();
                    teacher.AppendChild(login);
                    teacher.AppendChild(fullName);
                    teacher.AppendChild(password);
                    root.AppendChild(teacher);
                    xmlDocument.Save("..\\..\\users.xml");
                    MessageBox.Show("This user has been successfully created!", "Success", MessageBoxButtons.OK);
                    this.Close();
                }
            }
        }
    }
}
