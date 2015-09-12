using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    // provides audit services
    class Auditor
    {
        // non-static fields

        public readonly string name;

        // constructor

        public Auditor(string name_)
        {
            name = name_;
        }

        // non-static methods

        // checks given deal. this method is just abstraction
        public bool checkDeal(Deal dealToCheck)
        {
            bool isDealFair;

            // we get fairness of the deal
            dealToCheck.GetFairness(this, out isDealFair);

            Random rand = new Random((int)DateTime.Now.Ticks & 0x0000FFFF);

            // auditor makes a mistake in 2 % of cases
            if (rand.Next(1, 20) % 10 == 0)
            {
                isDealFair = !isDealFair;
            }

            return isDealFair;
        }
    }
}
