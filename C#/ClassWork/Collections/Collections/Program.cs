using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Collections
{
    class Program
    {
        static void Main(string[] args)
        {

            AdNetwork.Clip[] clips = new AdNetwork.Clip[4] { new AdNetwork.Clip("1.avi", 120, 30), new AdNetwork.Clip("2.avi", 100, 45), 
                new AdNetwork.Clip("3.avi", 180, 40), new AdNetwork.Clip("4.avi", 80, 15) };

            AdNetwork test = new AdNetwork(clips, new int[5]{1, 2, 3, 4, 5});

            test.StartWork();
        }
    }
}
