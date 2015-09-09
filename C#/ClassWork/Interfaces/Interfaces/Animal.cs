using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    abstract class Animal
    {
        // non-static fields 
        public readonly string name, classOfAnimal;

        // constructor
        public Animal( string name_, string classOfAnimal_ ) { name = name_; classOfAnimal = classOfAnimal_; }
    }
}
