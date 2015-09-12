using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    class Program
    {
        static void Main(string[] args)
        {
            Bank bank = new Bank("Bank", "Auditor");
            Contractor contractor;
            string name = "Contractor";
            Random rand = new Random((int)DateTime.Now.Ticks & 0x0000FFFF);

            // all customers will be new
            for (int i = 0; i < 5000; ++i )
            {
                contractor = new Contractor(name + i.ToString());
                contractor.makeDeal(bank, rand.Next(0, 2000000));
            }

            // some of customers will be regular fair ones, some - unfair and some - new ones
            for (int i = 0; i < 6000; ++i)
            {
                contractor = new Contractor(name + i.ToString());
                contractor.makeDeal(bank, rand.Next(0, 2000000));
            }

            // compairing results 
            bank.GetStatistics();

            Console.ReadKey();
        }
    }
}
