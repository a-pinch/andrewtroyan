using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zoo
{
    class Dog : Animal
    {
        // constructor
        public Dog(string name_) : base(name_) { }

        // non-static method
        override public void Voice()
        {
            Console.WriteLine("Dog {0} says woof!", name);
        }
    }
}
