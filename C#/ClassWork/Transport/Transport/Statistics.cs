using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Transport
{
    // provides statistics methods (evaluates average and median values)

    class Statistics
    {
        // non-static

        string fileNameWithCapacities, fileNameWithWaitings;
        string fileNameForCapacityStat, fileNameForWaitStat;
        int maxCapacityOfTrain;

        // constructor

        public Statistics(string fileNameWithCapacities_, string fileNameWithWaitings_, string fileNameForCapacityStat_, string fileNameForWaitStat_, int maxCapacityOfTrain_)
        {
            fileNameWithCapacities = fileNameWithCapacities_;
            fileNameWithWaitings = fileNameWithWaitings_;
            fileNameForCapacityStat = fileNameForCapacityStat_;
            fileNameForWaitStat = fileNameForWaitStat_;
            maxCapacityOfTrain = maxCapacityOfTrain_;
        }

        // non-static methods

        // gets all statistics (about occupancy and waiting indices)
        public void GetStatics()
        {
            using (StreamWriter fileTo = new StreamWriter(fileNameForCapacityStat, true))
            {
                double averageRelated, medianRelated;
                bool result = GetAverageCapacity(fileNameWithCapacities, maxCapacityOfTrain, out averageRelated, out medianRelated);

                if (result == true)
                {
                    fileTo.WriteLine("{0};{1};", averageRelated, medianRelated);
                }
            }

            File.WriteAllText(fileNameWithCapacities, String.Empty);


            using (StreamWriter fileTo = new StreamWriter(fileNameForWaitStat, true))
            {
                int average, median;
                bool result = GetAverageWaiting(fileNameWithWaitings, out average, out median);

                if (result == true)
                {
                    fileTo.WriteLine("{0};{1};", average, median);
                }
            }

            File.WriteAllText(fileNameWithWaitings, String.Empty);
        }

        // static methods

        public static bool GetAverageCapacity(string fileName, int max_amount, out double relatedToMax, out double median)
        {
            List<int> values = new List<int>();
            int average_amount = 0;
            int total_amount = 0;
            int num_buffer;
            string string_buffer;

            using (StreamReader file = new StreamReader(fileName))
            {
                while (file.EndOfStream == false)
                {
                    string_buffer = file.ReadLine();
                    num_buffer = Int32.Parse(string_buffer);
                    total_amount += num_buffer;
                    values.Add(num_buffer);
                }
            }

            if (values.Count > 0)
            {
                average_amount = total_amount / values.Count;
                relatedToMax = (double)average_amount / max_amount;
                median = (double)values[values.Count / 2] / max_amount;
                values.Clear();

                return true;
            }
            else
            {
                relatedToMax = 0;
                median = 0;

                return false;
            }
        }

        public static bool GetAverageWaiting(string fileName, out int average, out int median)
        {
            List<int> values = new List<int>();
            int average_amount = 0;
            int total_amount = 0;
            int num_buffer;
            string string_buffer;

            using (StreamReader file = new StreamReader(fileName))
            {
                while (file.EndOfStream == false)
                {
                    string_buffer = file.ReadLine();
                    num_buffer = Int32.Parse(string_buffer);
                    total_amount += num_buffer;
                    values.Add(num_buffer);
                }
            }

            if (values.Count > 0)
            {
                average_amount = total_amount / values.Count;
                average = average_amount;
                median = values[values.Count / 2];
                values.Clear();

                return true;
            }
            else
            {
                average = 0;
                median = 0;

                return false;
            }
        }
    }
}
