using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    // provides all objects that we're going to need in this application

    static class MainObjects
    {
        public static EventQueue queue = new EventQueue();

        public static Station[] stations = new Station[5] { new Station("Minsk", 2), new Station("Osipovichi", 15),
            new Station("Bobruisk", 7), new Station("Zhlobin", 12), new Station("Gomel", 4)};

        public static Train[] trains = new Train[5] { new Train(), new Train(), new Train(), new Train(), new Train() };

        public static string fileNameForWaitings = "..\\..\\Statistics\\passengersWaitings.txt";
        public static string fileNameForCapacity = "..\\..\\Statistics\\trainCapacity.txt";
        public static string fileNameForWaitingsStat = "..\\..\\Statistics\\waitingStat.txt";
        public static string fileNameForCapacityStat = "..\\..\\Statistics\\capacityStat.txt";

        public static Statistics statistics = new Statistics(fileNameForCapacity, fileNameForWaitings, fileNameForCapacityStat, fileNameForWaitingsStat, Train.MAX_CAPACITY);
    }
}
