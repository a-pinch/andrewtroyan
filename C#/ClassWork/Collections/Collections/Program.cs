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
            Clip[] clips = new Clip[3] { new Clip("1.avi", 2, 1),
                new Clip("2.avi", 2, 1), new Clip("3.avi",  2, 1) };

            AdNetwork ad_network = new AdNetwork(clips, new int[4] { 0, 1, 2, 3 });
            ad_network.startWork();
        }
    }
}
