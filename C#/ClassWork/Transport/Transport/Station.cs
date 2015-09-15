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

        public readonly string name;
        uint passengerArrivalPeriod;
        Queue<Passenger> passengers;

        // constructor

        public Station(string name_, uint passengerArrivalPeriod_)
        {
            name = name_;
            passengerArrivalPeriod = passengerArrivalPeriod_;
            passengers = new Queue<Passenger>();
        }

        // non-static methods

        public void AddPassengerOnArrival(uint time)
        {
            passengers.Enqueue(new Passenger(name, time));
            Program.queue.Add(time + passengerArrivalPeriod, AddPassengerOnArrival);
        }
    }
}
