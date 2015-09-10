using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
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
        public bool checkDeal(Deal dealToCheck)
        {

            return default(bool);
        }
    }
}
