using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    // represents a customer that can make deals
    class Contractor
    {
        // non-static fields

        public readonly string name;

        // constructor

        public Contractor(string name_)
        {
            name = name_;
        }

        // non-static methods

        public void makeDeal(Bank bank, int amountOfMoney)
        {
            Random rand = new Random((int)DateTime.Now.Ticks & 0x0000FFFF);
            bool isFair;

            if (amountOfMoney >= 1000000)
            {
                // if the sum is pretty big contractor wants to make an unfair deal in 10 % of cases
                if (rand.Next(1, 10) % 10 == 0)
                {
                    isFair = false;
                }
                else
                {
                    isFair = true;
                }
            }
            else
            {
                // if the sum is not so big contractor wants to make an unfair deal in 20 % of cases
                if (rand.Next(1, 10) % 5 == 0)
                {
                    isFair = false;
                }
                else
                {
                    isFair = true;
                }
            }

            bank.addDeal(new Deal(this, amountOfMoney, isFair));
        }
    }
}
