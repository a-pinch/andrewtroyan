using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    class Program
    {
        public static EventQueue queue = new EventQueue(); 

        static void Main(string[] args)
        {
            Station minsk = new Station("Minsk", 2);
            Station osipovichi = new Station("Osipovichi", 15);

            queue.Add(0, minsk.AddPassengerOnArrival);
            queue.Add(1, osipovichi.AddPassengerOnArrival);

            uint time = 0;

            while (time < 100)
            {
                if (queue.ContainsKey(time))
                {
                    foreach (var transportEvent in queue[time])
                    {
                        transportEvent(time);
                    }
                }

                ++time;
            }

            Console.ReadKey();
        }
    }
}
