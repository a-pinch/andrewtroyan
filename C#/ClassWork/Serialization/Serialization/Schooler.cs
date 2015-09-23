using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Serialization
{
    [Serializable]
    public class Schooler
    {
        // non-static fields

        public string _name;
        public int[] _marks;
        public string[] _penCase;

        // constructors

        public Schooler() 
        {
            _name = null;
            _marks = null;
            _penCase = null;
        }

        public Schooler(string name, int[] marks, string[] penCase)
        {
            _name = name;
            _marks = marks;
            _penCase = penCase;
        }
    }
}
