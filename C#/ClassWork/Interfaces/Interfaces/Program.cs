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
                try{
                    IFlyer flyer = (IFlyer)an;
                    flyer.fly();
                }
                catch (InvalidCastException e)
                {
                    Console.WriteLine(e.Message);
                }
            }

            Console.ReadKey();
        }
    }
}
