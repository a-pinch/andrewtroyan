using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    class Passenger
    {
        // static fields

        public static int countingNumber = 0;

        // non-static fields

        public string name;
        public Train relatedTrain;
        public Station from, to;

        // constructor 

        public Passenger(string name_, uint time, Station station)
        {
            name = name_;
            from = station;
            relatedTrain = null;

            Random rand = new Random();
            int indexOfCurrentStation = Array.FindIndex(Program.stations, (st) => st == station);
            int indexOfLastStation = Program.stations.Length - 1;
            to = Program.stations[rand.Next(indexOfCurrentStation + 1, indexOfLastStation)];

            Console.WriteLine("{0} came to {1} station at {2} (destination - {3}).", name, from.name, time, to.name);
        }

        // non-static methods

        public void StepOut(Train train, uint time)
        {
            Console.WriteLine("{0} is stepping out the train {1} at {2}.", name, train.number, time);
        }

        public void StepOn(Train train, uint time)
        {
            Console.WriteLine("{0} is stepping on the train {1} at {2}.", name, train.number, time);
        }
    }
}
