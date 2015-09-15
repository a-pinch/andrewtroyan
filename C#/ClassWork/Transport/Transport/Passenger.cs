using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    class Passenger
    {
        // constructor 

        public Passenger(string stationName, uint time)
        {
            Console.WriteLine("A passenger came to {0} station at {1}.", stationName, time);
        }
    }
}
