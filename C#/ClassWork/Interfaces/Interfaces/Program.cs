using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Interfaces
{
    class Program
    {
        static void Main(string[] args)
        {
            Animal[] animals = new Animal[3] { new Bird("Ammie"), new Fox("Foxie"), new Bird("Twinky") };

            foreach(var an in animals)
            {
                if (an is IFlyer)
                {
                    IFlyer flyer = an as IFlyer;
                    flyer.fly();
                }
                else
                { 
                    Console.WriteLine("The " + an.classOfAnimal + " " + an.name + " cannot fly!");
                }
            }

            Console.ReadKey();
        }
    }
}
