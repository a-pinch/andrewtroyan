using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zoo
{
    class Cat : Animal
    {
        // constructor
        public Cat(string name_) : base(name_) {}

        // non-static method
        override public void Voice()
        {
            Console.WriteLine(String.Format("Cat {0} says meow!", name));
        }
    }
}
