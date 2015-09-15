using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    class Station
    {
        // non-static fields

        string name;
        uint passengerArrivalPeriod;
        Queue<Passenger> passengers;

        // constructor

        public Station(string name_, uint passengerArrivalPeriod_)
        {
            name = name_;
            passengerArrivalPeriod = passengerArrivalPeriod_;
            passengers = new Queue<Passenger>();
        }

        // static methods

        public void AddPassengerOnArrival(uint time)
        {
            new Passenger(name, time);
            Program.queue.Add(time + passengerArrivalPeriod, AddPassengerOnArrival);
        }
    }
}
