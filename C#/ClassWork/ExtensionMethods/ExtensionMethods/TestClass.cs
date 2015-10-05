using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ExtensionMethods
{
    class TestClass
    {
        public string name;
        public int prop { get; set; }

        public TestClass(string name_, int prop_)
        {
            name = name_;
            prop = prop_;
        }
    }
}
