using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zoo
{
    abstract class Animal
    {
        // non-static field
        public readonly string name;

        // constructor
        protected Animal(string name_)
        {
            this.name = name_;
        }

        // non-static method
        abstract public void Voice();
    }
}
