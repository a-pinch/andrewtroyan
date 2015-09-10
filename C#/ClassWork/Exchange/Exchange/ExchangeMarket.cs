using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exchange
{
    class ExchangeMarket
    {
        // non-static fields
        Recorder recorder;
        Auditor auditor;
        private event EventHandler<Deal> bid;

        // constructor
        public ExchangeMarket()
        {
            bid += (obj, deal) => recorder.addDeal(deal);
            bid += (obj, deal) => auditor.addDeal(deal);
        }

        public void addDeal(Deal deal)
        {
            bid(this, deal);
        }
    }
}
