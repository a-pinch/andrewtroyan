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
        public static Station[] stations = new Station[5] { new Station("Minsk", 2), new Station("Osipovichi", 15),
            new Station("Bobruisk", 7), new Station("Zhlobin", 12), new Station("Gomel", 4)};
        public static Train train = new Train();

        static void Main(string[] args)
        {
            queue.Add(0, stations[0].AddPassengerOnArrival);
            queue.Add(1, stations[1].AddPassengerOnArrival);
            queue.Add(0, stations[2].AddPassengerOnArrival);
            queue.Add(1, stations[3].AddPassengerOnArrival);

            queue.Add(3, train.OnArrival);

            uint time = 0;
            
            while (time < 250)
            {
                if (queue.ContainsKey(time))
                {
                    foreach (var transportEvent in queue[time])
                    {
                        transportEvent(time);
                    }

                    queue.Remove(time);
                }

                ++time;
            }
            
            Console.ReadKey();
        }
    }
}
