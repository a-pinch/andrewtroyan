using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace MedianSalary
{
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

        public int GetMedianSalary(out int dispersion)
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

            if (salaries.Count == 0)
            {
                dispersion = 0;
                return 0;
            }
            if (salaries.Count == 1)
            {
                dispersion = 0;
                return salaries[0];
            }
            else
            {
                int median = salaries[salaries.Count / 2];
                int firstQuarter = salaries[salaries.Count / 4];
                int lastQuarter = salaries[salaries.Count * 3 / 4];

                dispersion = ((median - firstQuarter) + (lastQuarter - median)) / 2;
                return median;
            } 
        }
    }
}
