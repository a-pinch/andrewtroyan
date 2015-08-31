using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zoo
{
    class Program
    {
        static void Main(string[] args)
        {
            var animals = new Animal[5] { new Cat("Kitty"), new Cat("Mura"), new Cat("Sima"), new Dog("Sharik"), new Dog("Bobik") };

            foreach (var a in animals)
            {
                a.Voice();
            }

            Console.ReadKey();
        }
    }
}
