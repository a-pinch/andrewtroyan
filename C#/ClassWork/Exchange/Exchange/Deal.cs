using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exchange
{
    class Deal : EventArgs
    {
        public int rate, amount;

        public Deal(int rate_, int amount_)
        {
            rate = rate_;
            amount = amount_;
        }
    }
}
