using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Collections
{
    class Program
    {
        static void Main(string[] args)
        {
            Clip[] clips = new Clip[3] { new Clip("1.avi", 30, 5),
                new Clip("2.avi", 45, 9), new Clip("3.avi",  60, 10) };

            AdNetwork ad_network = new AdNetwork(clips, new int[4] { 0, 1, 2, 3 });
            ad_network.startWork();

            Console.WriteLine("All data is registered.");
            Console.ReadKey();
        }
    }
}
