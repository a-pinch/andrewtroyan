using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MedianSalary
{
    // calculates median salary with dispersion from given file

    class WorkingOnMedianSalary
    {
        // non-static fields

        private string fileName;

        // constructor

        public WorkingOnMedianSalary(string fileName_)
        {
            fileName = fileName_;
        }

        // non-static fields

        public int GetMedianSalary()
        {
            List<int> salaries = new List<int>();

            string buffer;

            using (StreamReader file = new StreamReader(fileName))
            {
                while (file.EndOfStream == false)
                {
                    buffer = file.ReadLine();
                    salaries.Add(Int32.Parse(buffer));
                }
            }

            int size = salaries.Count;

            if (size == 0)
            {
                return 0;
            }
            else
            {
                var orderedSalaries = salaries.OrderBy(salary => salary);
                int median = orderedSalaries.ElementAt(size / 2);
                return median;
            }
        }
    }
}
