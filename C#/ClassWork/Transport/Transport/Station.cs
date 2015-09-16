using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    // determines a station

    class Station
    {
        // non-static fields

        public readonly string name;
        // in what amount of time the next passenger comes (in minutes)
        uint passengerArrivalPeriod;
        // queue of passengers at the station
        Queue<Passenger> passengers;

        // constructor

        public Station(string name_, uint passengerArrivalPeriod_)
        {
            name = name_;
            passengerArrivalPeriod = passengerArrivalPeriod_;
            passengers = new Queue<Passenger>();
        }

        // non-static methods

        // when new passenger comes to the station
        public void AddPassengerOnArrival(uint time)
        {
            if (this != MainObjects.stations[MainObjects.stations.Length - 1])
            {
                string passengerName = "Passenger " + (Passenger.countingNumber++).ToString();
                Passenger newPassenger = new Passenger(passengerName, time, this);
                passengers.Enqueue(newPassenger);
                MainObjects.queue.Add(time + passengerArrivalPeriod, AddPassengerOnArrival);
            }
        }

        // when train comes certain amount of people steps out the train
        // the station manages all of this
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

        // when train is going to the next station people need to catch the train
        // the station manages all this work
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
