using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class Pupil
    {
        // non-static fields

        public string name;

        // constructors

        public Pupil()
        {
            name = default(string);
        }

        public Pupil(string name_)
        {
            name = name_; 
        }
    }
}
