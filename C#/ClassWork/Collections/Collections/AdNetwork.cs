using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Collections
{
    class AdNetwork
    {
        // struct in class

        public struct Clip
        {
            public readonly string name;
            public readonly int paid_time; // in minutes
            public readonly int length; // in seconds
            public int left_time;

            public Clip(string name_, int paid_time_, int length_)
            {
                name = name_;
                paid_time = paid_time_;
                length = length_;
                left_time = paid_time * 60;
            }
        }

        // non-static fields

        private List<Clip> clips;
        private int[] TVidentifiers;

        // constructor

        public AdNetwork(Clip[] clips_, int[] TVidentifiers_)
        {
            clips = new List<Clip>();

            foreach(Clip clip in clips_)
            {
                clips.Add(clip);
            }

            TVidentifiers = TVidentifiers_;
        }

        // non-static methods

        public void StartWork()
        {
            foreach(int tv in TVidentifiers) 
            {
                int hours = 6; 
                double minutes = 0;

                //FileStream tv_file = new FileStream("TV\\" + tv + ".txt", FileMode.Append, FileAccess.Write);
                FileStream tv_file = new FileStream("D:\\1.txt", FileMode.Append, FileAccess.Write);
                StreamWriter tv_writer = new StreamWriter(tv_file);

                foreach(Clip clip in clips)
                {
                    if (clip.left_time >= clip.length)
                    {
                        //FileStream clip_file = new FileStream("Clips\\" + clip.name + ".txt", FileMode.Append, FileAccess.Write);
                        FileStream clip_file = new FileStream("D:\\2.txt", FileMode.Append, FileAccess.Write);
                        StreamWriter clip_writer = new StreamWriter(clip_file);

                        clip_writer.WriteLine(tv + " " + hours + ":" + (int)minutes + " ");
                        tv_writer.WriteLine(clip.name + " " + hours + ":" + (int)minutes);

                        minutes += clip.length / 10.0;
                        if (minutes >= 60.0)
                        {
                            ++hours;
                            minutes = 0;
                        }

                        clip_writer.Close();
                        clip_file.Close();
                    }
                }

                tv_writer.Close();
                tv_file.Close();
            }
        }
    }
}
