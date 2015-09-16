using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Transport
{
    // determines a passenger

    class Passenger
    {
        // static fields (used for names generating)

        public static int countingNumber = 0;

        // non-static fields

        public string name;
        public Train relatedTrain;
        public Station from, to;
        // startOfWaiting - when a passenger comes to the station, endOfWaitin - when he starts to go by train
        public uint startOfWaiting, endOfWaiting;

        // constructor 

        public Passenger(string name_, uint time, Station station)
        {
            name = name_;
            from = station;
            relatedTrain = null;
            startOfWaiting = time;

            // determines where the passenger is going
            Random rand = new Random();
            int indexOfCurrentStation = Array.FindIndex(MainObjects.stations, (st) => st == station);
            int indexOfLastStation = MainObjects.stations.Length - 1;
            to = MainObjects.stations[rand.Next(indexOfCurrentStation + 1, indexOfLastStation)];

            Console.WriteLine("{0} came to {1} station at {2} (destination - {3}).", name, from.name, time, to.name);
        }

        // non-static methods

        // when he steps out the train (he got to destination)
        public void StepOut(Train train, uint time)
        {
            Console.WriteLine("{0} is stepping out the train {1} at {2}.", name, train.number, time);
        }

        // when the train comes
        public void StepOn(Train train, uint time)
        {
            endOfWaiting = time;

            using (StreamWriter file = new StreamWriter(MainObjects.fileNameForWaitings, true))
            {
                file.WriteLine(endOfWaiting - startOfWaiting);
            }

            Console.WriteLine("{0} is stepping on the train {1} at {2}.", name, train.number, time);
        }
    }
}
