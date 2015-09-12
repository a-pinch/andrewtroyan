using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    // represents a bank's deal
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

        // non-static fields

        // auditor can get fairness of the deal (it's a part of abstract method of auditor's service)
        public bool GetFairness(object auditor, out bool fairness)
        {
            // we must ensure that AUDITOR is try to get fairness
            if (auditor is Auditor)
            {
                fairness = isFair;
                return true;
            }
            else
            {
                fairness = default(bool);
                return false;
            }
        }
    }
}
