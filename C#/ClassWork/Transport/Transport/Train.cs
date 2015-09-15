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
        public static int countingNumber = 0;

        // non-static fields

        public int number;
        public int currentStation;
        public int currentAmount;
        public List<Passenger> passengers;

        // constructor

        public Train()
        {
            number = Train.countingNumber++;
            currentStation = 0;
            currentAmount = 0;
            passengers = new List<Passenger>();
        }

        // non-static methods

        public void OnArrival(uint time)
        {
            Console.WriteLine("A train {0} came to {1} station at {2}.", number, Program.stations[currentStation].name, time);
            Program.stations[currentStation].TrainCame(this, time);

            Program.queue.Add(time + 5, OnDeparture);
        }

        public void OnDeparture(uint time)
        {
            if (currentStation + 1 < Program.stations.Length)
            {
                Program.stations[currentStation].TrainGoing(this, time);
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
