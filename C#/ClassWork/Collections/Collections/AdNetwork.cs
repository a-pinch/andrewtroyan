using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Threading;
using System.IO;

namespace Collections
{
    class AdNetwork
    {
        // non-static fields
        private List<Clip> clips;
        private int[] tv_identifiers;
        private List<Thread> tv_threads;

        private object file_locker;
        private object list_locker;

        // constructor
        public AdNetwork(Clip[] clips_, int[] tv_identifiers_)
        {
            clips = new List<Clip>();
            foreach(var clip in clips_)
            {
                clips.Add(clip);
            }

            tv_identifiers = tv_identifiers_;
            tv_threads = new List<Thread>();
            file_locker = new object();
            list_locker = new object();
        }

        // non-static methods
        public void startWork()
        {
            foreach (var tv in tv_identifiers)
            {
                Thread thread = new Thread(tvWorking);
                thread.Start(tv);
                tv_threads.Add(thread);
            }

            foreach (var thread in tv_threads)
            {
                thread.Join();
            }

            foreach (var clip in clips)
            {
                clip.output.Close();
                clip.file_stream.Close();
            }
        }

        private void tvWorking(object tv_index)
        {
            int index = (int)tv_index;
            string current_time;
            FileStream tv_file = new FileStream("..\\..\\TVs\\" + index + ".txt", FileMode.Append, FileAccess.Write);
            StreamWriter tv_flow = new StreamWriter(tv_file);
            int to_exit = 0; // if this variable is equal to amount of clips then exit
            bool to_continue = false;

            while (true)
            {
                foreach (var clip in clips)
                {
                    lock (list_locker)
                    {
                        if (clip.LeftTime >= clip.duration)
                        {
                            clip.LeftTime -= clip.duration;
                            to_continue = true;
                        }
                        else
                            to_continue = false;
                    }
                    if (to_continue)
                    {
                        current_time = DateTime.Now.ToString();

                        lock (file_locker)
                        {
                            clip.output.WriteLine(current_time + " " + index);
                        }

                        tv_flow.WriteLine(current_time + " " + clip.name);
                        Thread.Sleep(TimeSpan.FromSeconds(clip.duration));
                    }
                    else
                    {
                        ++to_exit;

                        if(to_exit == clips.Count)
                        {
                            tv_flow.Close();
                            tv_file.Close();
                            return;
                        }
                    }
                }
            }
        }
    }
}
