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
            Random rand = new Random();

            for (int i = 0; i < 100; ++i )
            {
                contractor = new Contractor(name + i.ToString());
                contractor.makeDeal(bank, rand.Next(0, 10000000));
            }

            Console.ReadKey();
        }
    }
}
