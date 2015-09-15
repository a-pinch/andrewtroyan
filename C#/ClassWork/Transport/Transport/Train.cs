using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    class Train
    {
        // static fields

        public static readonly int MAX_CAPACITY = 300;
        private static uint[] intervalsBetweenStations = new uint[] { 50, 30, 70, 40, 40};

        // non-static fields

        int currentStation;

        // constructor

        public Train()
        {
            currentStation = 0;
        }

        // non-static methods

        public void OnArrival(uint time)
        {
            Console.WriteLine("A train came to {0} station at {1}.", Program.stations[currentStation].name, time);

            Program.queue.Add(time + 5, OnDeparture);
        }

        public void OnDeparture(uint time)
        {
            if (currentStation + 1 < Program.stations.Length)
            {
                Console.WriteLine("A train is going to {0} station from {1} station at {2}.", 
                    Program.stations[currentStation + 1].name, Program.stations[currentStation].name, time);

                Program.queue.Add(time + intervalsBetweenStations[currentStation], OnArrival);
                ++currentStation;
            }
            else
            {
                Console.WriteLine("A train went to depot.");
            }
        }
    }
}
