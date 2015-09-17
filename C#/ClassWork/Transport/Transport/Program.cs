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
            // adding a few passengers per a station
            MainObjects.queue.Add(0, MainObjects.stations[0].AddPassengerOnArrival);
            MainObjects.queue.Add(0, MainObjects.stations[0].AddPassengerOnArrival);
            MainObjects.queue.Add(1, MainObjects.stations[0].AddPassengerOnArrival);

            MainObjects.queue.Add(1, MainObjects.stations[1].AddPassengerOnArrival);
            MainObjects.queue.Add(1, MainObjects.stations[1].AddPassengerOnArrival);
            MainObjects.queue.Add(2, MainObjects.stations[1].AddPassengerOnArrival);

            MainObjects.queue.Add(0, MainObjects.stations[2].AddPassengerOnArrival);
            MainObjects.queue.Add(0, MainObjects.stations[2].AddPassengerOnArrival);
            MainObjects.queue.Add(1, MainObjects.stations[2].AddPassengerOnArrival);

            MainObjects.queue.Add(1, MainObjects.stations[3].AddPassengerOnArrival);
            MainObjects.queue.Add(1, MainObjects.stations[3].AddPassengerOnArrival);
            MainObjects.queue.Add(2, MainObjects.stations[3].AddPassengerOnArrival);

            // adding trains at different time
            MainObjects.trains.Add(new Train());
            MainObjects.queue.Add(0, MainObjects.trains[0].OnArrival);

            uint time = 0;

            while (time < 6000)
            {
                if (time % 38 == 0)
                {
                    MainObjects.trains.Add(new Train());
                    MainObjects.queue.Add(time + 38, MainObjects.trains[MainObjects.trains.Count - 1].OnArrival);
                }

                if (MainObjects.queue.ContainsKey(time))
                {
                    foreach (var transportEvent in MainObjects.queue[time])
                    {
                        transportEvent(time);
                    }

                    MainObjects.queue.Remove(time);
                }

                if (time % 150 == 0)
                {
                    MainObjects.statistics.GetStatics();
                }

                ++time;
            }
            
            Console.ReadKey();
        }
    }
}
