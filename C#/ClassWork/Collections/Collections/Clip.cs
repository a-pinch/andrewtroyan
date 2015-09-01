using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Collections
{
    class Clip
    {
        // non-static fields
        public readonly string name;
        public readonly uint duration; // in seconds
        public FileStream file_stream;
        public StreamWriter output;

        private readonly uint paid_time; // in seconds
        private uint left_time; // in seconds

        // constructor
        public Clip(string name_, uint paid_time_, uint duration_)
        {
            name = name_;
            paid_time = paid_time_;
            left_time = paid_time_;
            duration = duration_;

            file_stream = new FileStream("..\\..\\Clips\\" + name + ".txt", FileMode.Append, FileAccess.Write);
            output = new StreamWriter(file_stream);
        }

        // properties
        public uint LeftTime
        {
            set
            {
                left_time = value;
            }
            get
            {
                return left_time;
            }
        }
    }
}
