using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exchange
{
    class Auditor
    {
        private List<Deal> deals;

        public void addDeal(Deal deal)
        {
            deals.Add(deal);
        }
    }
}
