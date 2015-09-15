using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    delegate void TransportEvent();

    class Program
    {
        public static SortedDictionary<uint, TransportEvent> eventQueue = new SortedDictionary<uint, TransportEvent>();

        static void Main(string[] args)
        {
        }
    }
}
