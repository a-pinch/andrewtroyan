using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Transport
{
    class Program
    {
        static void Main(string[] args)
        {
            // adding a passenger per a station
            MainObjects.queue.Add(0, MainObjects.stations[0].AddPassengerOnArrival);
            MainObjects.queue.Add(1, MainObjects.stations[1].AddPassengerOnArrival);
            MainObjects.queue.Add(0, MainObjects.stations[2].AddPassengerOnArrival);
            MainObjects.queue.Add(1, MainObjects.stations[3].AddPassengerOnArrival);

            // adding trains at different time
            MainObjects.queue.Add(0, MainObjects.trains[0].OnArrival);
            MainObjects.queue.Add(230, MainObjects.trains[1].OnArrival);
            MainObjects.queue.Add(460, MainObjects.trains[2].OnArrival);
            MainObjects.queue.Add(690, MainObjects.trains[3].OnArrival);
            MainObjects.queue.Add(920, MainObjects.trains[4].OnArrival);

            uint time = 0;

            while (time < 1000)
            {
                if (MainObjects.queue.ContainsKey(time))
                {
                    foreach (var transportEvent in MainObjects.queue[time])
                    {
                        transportEvent(time);
                    }

                    MainObjects.queue.Remove(time);
                }

                if (time % 250 == 0)
                {
                    MainObjects.statistics.GetStatics();
                }

                ++time;
            }

            MainObjects.statistics.GetStatics();
            
            Console.ReadKey();
        }
    }
}
