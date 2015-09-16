using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Transport
{
    class Program
    {
        public static EventQueue queue = new EventQueue();
        public static Station[] stations = new Station[5] { new Station("Minsk", 2), new Station("Osipovichi", 15),
            new Station("Bobruisk", 7), new Station("Zhlobin", 12), new Station("Gomel", 4)};
        public static Train train_1 = new Train(), train_2 = new Train(), train_3 = new Train(), train_4 = new Train(), train_5 = new Train();

        public static string fileNameForWaitings = "..\\..\\passengersWaitings.txt";
        public static string fileNameForCapacity = "..\\..\\trainCapacity.txt";
        public static string fileNameForWaitingsStat = "..\\..\\capacityStat.txt";
        public static string fileNameForCapacityStat = "..\\..\\waitingStat.txt";

        public static Statistics statistics = new Statistics(fileNameForCapacity, fileNameForWaitings, fileNameForCapacityStat, fileNameForWaitingsStat, Train.MAX_CAPACITY);

        static void Main(string[] args)
        {
            queue.Add(0, stations[0].AddPassengerOnArrival);
            queue.Add(1, stations[1].AddPassengerOnArrival);
            queue.Add(0, stations[2].AddPassengerOnArrival);
            queue.Add(1, stations[3].AddPassengerOnArrival);

            queue.Add(0, train_1.OnArrival);
            queue.Add(230, train_2.OnArrival);
            queue.Add(460, train_3.OnArrival);
            queue.Add(690, train_4.OnArrival);
            queue.Add(920, train_5.OnArrival);

            uint time = 0;

            while (time < 1000)
            {
                if (queue.ContainsKey(time))
                {
                    foreach (var transportEvent in queue[time])
                    {
                        transportEvent(time);
                    }

                    queue.Remove(time);
                }

                if (time % 250 == 0)
                {
                    statistics.GetStatics();
                }

                ++time;
            }

            //double averageRelatedCapacity, medianRelatedCapacity;

            //Statistics.GetAverageCapacity(fileNameForCapacity, Train.MAX_CAPACITY, out averageRelatedCapacity, out medianRelatedCapacity);
            //Console.WriteLine("Average amount related to max amount of passengers - {0}, median - {1}.", averageRelatedCapacity, medianRelatedCapacity);

            //int averageWaiting, medianWaiting;
            //averageWaiting = Statistics.GetAverageWaiting(fileNameForWaitings, out medianWaiting);
            //Console.WriteLine("Average waiting of passengers - {0}, median - {1}.", averageWaiting, medianWaiting);
            
            Console.ReadKey();
        }
    }
}
