using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
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

            processDeal = (deal) =>
                {
                    bool isFair = auditor.checkDeal(deal);
                    moneyForAuditor += deal.money * 0.01;

                    if (isFair == false)
                    {
                        unFairContractors.Add(deal.contractor);
                        exposedUnfairDealsMoney += deal.money;
                    }

                    return isFair;
                };
        }

        // non-static methods
        public bool addDeal(Deal deal)
        {
            bool result = true;

            if (unFairContractors.Find(contr => deal.contractor.name == contr.name) != default(Contractor))
            {
                result = false;
            }
            else if (regularContractors.Find(contr => deal.contractor.name == contr.name) != default(Contractor))
            {
                if (new Random().Next(1, 5) % 5 == 0)
                {
                    result = processDeal(deal);
                }
            }
            else
            {
                result = processDeal(deal);

                if (result == false)
                {
                    unFairContractors.Add(deal.contractor);
                }
                else
                {
                    regularContractors.Add(deal.contractor);
                }
            }

            return result;
        }
    }
}
