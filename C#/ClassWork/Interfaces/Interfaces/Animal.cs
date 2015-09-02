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
        public readonly string name;

        // constructor
        public Animal( string name_ ) { name = name_; }
    }
}
