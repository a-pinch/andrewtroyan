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
            WorkingOnMedianSalary salaryWork = new WorkingOnMedianSalary("..\\..\\..\\..\\HTTPrequest\\HTTPrequest\\salaries.csv");

            int medianSalary = salaryWork.GetMedianSalary();

            Console.WriteLine("Average salary: {0} BYR.", medianSalary);
            Console.ReadKey();
        }
    }
}
