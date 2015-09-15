using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    class Passenger
    {
        public readonly string from, to;

        public Passenger(string from_, string to_)
        {
            from = from_;
            to = to_;
        }
    }
}
