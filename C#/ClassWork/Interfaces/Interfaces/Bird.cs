using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    class Bird : Animal, IFlyer
    {
        // constructor
        public Bird(string name) : base(name, "bird") { }

        public void fly()
        {
            Console.WriteLine("The " + classOfAnimal + " " + name + " is flying...");
        }
    }
}
