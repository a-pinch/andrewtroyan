using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    // provides bank services. this class contains its own auditor, lists of clients (regular and unfair ones),
    // expenses for auditor services and total sum of unfair deals
    class Bank
    {
        // non-static fields;

        public readonly string nameOfBank;
        private Auditor auditor;
        private double moneyForAuditor, exposedUnfairDealsMoney;
        private List<Contractor> unFairContractors, regularContractors;
        private AuditCheck processDeal;

        // constructor

        public Bank(string nameOfBank_, string nameOfAuditor_)
        {
            nameOfBank = nameOfBank_;
            auditor = new Auditor(nameOfAuditor_);
            unFairContractors = new List<Contractor>();
            regularContractors = new List<Contractor>();

            // processing a deal (first auditor checks it and then we add or remove a client from an appropriate list)
            // also we increment our expenses
            processDeal = (deal) =>
                {
                    bool isFair = auditor.checkDeal(deal);
                    // auditor fee is 0.2% of a deal's sum
                    moneyForAuditor += deal.money * 0.002;

                    if (isFair == false)
                    {
                        if (regularContractors.Find(contr => contr.name == deal.contractor.name) != default(Contractor))
                        {
                            regularContractors.Remove(deal.contractor);
                        }

                        unFairContractors.Add(deal.contractor);
                        exposedUnfairDealsMoney += deal.money;
                    }
                    else
                    {
                        if (regularContractors.Find(contr => contr.name == deal.contractor.name) == default(Contractor))
                        {
                            regularContractors.Add(deal.contractor);
                        }
                    }
                    
                    return isFair;
                };
        }

        // non-static methods

        public bool addDeal(Deal deal)
        {
            bool result = true;

            // if it's an unfair client we deny his request
            if (unFairContractors.Find(contr => contr.name == deal.contractor.name) != default(Contractor))
            {
                result = false;
            }
            // if it's an established customer
            else if (regularContractors.Find(contr => contr.name == deal.contractor.name) != default(Contractor))
            {
                Random rand = new Random((int)DateTime.Now.Ticks & 0x0000FFFF);
                // probability of checking our established customers is 20 %
                if (rand.Next(1, 5) % 5 == 0)
                {
                    result = processDeal(deal);
                }
            }
            // if it's a new customer we check him anyway
            else
            {
                result = processDeal(deal);
            }

            return result;
        }

        // we can compare our expenses for audit services and total sum of unfair deals with this method
        public void GetStatistics()
        {
            Console.WriteLine("Money dropped on auditor: {0}", moneyForAuditor);
            Console.WriteLine("Total sum of unfair deals: {0}", exposedUnfairDealsMoney);
        }
    }
}
