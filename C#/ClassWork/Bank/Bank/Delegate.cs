using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Bank
{
    // just a delegate that we can use for auditor's checking
    delegate bool AuditCheck(Deal deal);
}
