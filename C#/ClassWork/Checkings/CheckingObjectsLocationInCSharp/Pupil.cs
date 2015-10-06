using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CheckingObjectsLocationInCSharp
{
    class Pupil
    {
        public string name;
        public int age;

        public Pupil()
        {
            name = "";
            var rand = new Random((int)DateTime.Now.Ticks);

            int nameLength = rand.Next(5, 8);
            for (int i = 0; i < nameLength; ++i)
            {
                name += (char)rand.Next(97, 123);
            }

            age = rand.Next(1, 99);
        }
    }
}
