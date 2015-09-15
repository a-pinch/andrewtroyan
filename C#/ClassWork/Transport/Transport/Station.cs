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
            if (this != Program.stations[Program.stations.Length - 1])
            {
                passengers.Enqueue(new Passenger("Passenger " + (Passenger.countingNumber++).ToString(), time, this));
                Program.queue.Add(time + passengerArrivalPeriod, AddPassengerOnArrival);
            }
        }

        public void TrainCame(Train train, uint time)
        {
            int passengersGone = 0;

            train.passengers.RemoveAll( passenger =>
            {
                if (passenger.to == this)
                {
                    passenger.StepOut(train, time);
                    ++passengersGone;
                    return true;
                }
                else
                {
                    return false;
                }
            });

            train.currentAmount -= passengersGone;
        }
        
        public void TrainGoing(Train train, uint time)
        {
            while (train.currentAmount < Train.MAX_CAPACITY && passengers.Count > 0)
            {
                var passenger = passengers.Dequeue();
                passenger.relatedTrain = train;
                passenger.StepOn(train, time);
                train.passengers.Add(passenger);
                ++train.currentAmount;
            }
        }
    }
}
