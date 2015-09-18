using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MedianSalary
{
    class Program
    {
        static void Main(string[] args)
        {
            WorkingOnMedianSalary salaryWork = new WorkingOnMedianSalary("..\\..\\..\\HTTPrequest\\salaries.csv");

            int medianSalary, dispersion;
            medianSalary = salaryWork.GetMedianSalary(out dispersion);

            Console.WriteLine("Median salary: {0} +- {1} BYR.", medianSalary, dispersion);
            Console.ReadKey();
        }
    }
}
