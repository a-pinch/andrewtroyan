using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    class Deal
    {
        // non-static fields
        public Contractor contractor;
        public double money;
        private bool isFair;

        // constructor
        public Deal(Contractor contractor_, int money_, bool isFair_)
        {
            contractor = contractor_;
            money = money_;
            isFair = isFair_;
        }
    }
}
