using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SchoolJournal
{
    [Serializable]
    public class Subject
    {
        // non-static fields

        public string name;
        public List<string> topics;

        // constructors

        public Subject()
        {
            name = default(string);
            topics = new List<string>();
        }

        public Subject(string name_, List<string> topics_)
        {
            name = name_;
            topics = topics_;
        }
    }
}
