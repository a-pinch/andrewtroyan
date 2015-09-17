using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Transport
{
    class Train
    {
        // static fields

        public static readonly int MAX_CAPACITY = 200;
        private static uint[] intervalsBetweenStations = new uint[] { 50, 30, 70, 40 };
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
            Console.WriteLine("A train {0} came to {1} station at {2}.", number, MainObjects.stations[currentStation].name, time);
            MainObjects.stations[currentStation].TrainCame(this, time);

            MainObjects.queue.Add(time + 5, OnDeparture);
        }

        public void OnDeparture(uint time)
        {
            if (currentStation + 1 < MainObjects.stations.Length)
            {
                MainObjects.stations[currentStation].TrainGoing(this, time);

                using (StreamWriter file = new StreamWriter(MainObjects.fileNameForCapacity, true))
                {
                    file.WriteLine(currentAmount);
                }


                Console.WriteLine("A train {0} is going to {1} station from {2} station at {3}.", number,
                    MainObjects.stations[currentStation + 1].name, MainObjects.stations[currentStation].name, time);

                MainObjects.queue.Add(time + intervalsBetweenStations[currentStation], OnArrival);
                ++currentStation;
            }
            else
            {
                Console.WriteLine("A train went to depot.");
            }
        }
    }
}
