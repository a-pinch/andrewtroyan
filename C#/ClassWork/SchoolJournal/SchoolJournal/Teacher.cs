using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class Teacher
    {
        // non-static fields

        public string name;

        // constructors

        public Teacher()
        {
            name = default(string);
        }

        public Teacher(string name_)
        {
            name = name_;
        }
    }
}
