using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    class Contractor
    {
        public readonly string name;

        public Contractor(string name_)
        {
            name = name_;
        }

        public void makeDeal(Bank bank, int amountOfMoney)
        {
            Random rand = new Random();
            bool isFair;

            if (amountOfMoney >= 5000000)
            {
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
