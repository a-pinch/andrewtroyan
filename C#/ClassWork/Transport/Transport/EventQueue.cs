using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    delegate void TransportEvent(uint time);

    class EventQueue
    {
        // non-static fields

        private SortedDictionary<uint, List<TransportEvent>> queue;

        // constructor

        public EventQueue()
        {
            queue = new SortedDictionary<uint, List<TransportEvent>>();
        }

        // non-static fields 

        public void Add(uint index, TransportEvent transportEvent)
        {
            if (queue.ContainsKey(index) == false)
            {
                queue[index] = new List<TransportEvent>();
            }

            queue[index].Add(transportEvent);
        } 

        public void Remove(uint index)
        {
            if (queue.ContainsKey(index))
            {
                queue[index].Clear();
                queue.Remove(index);
            }
        }

        public bool ContainsKey(uint index_)
        {
            return queue.ContainsKey(index_);
        }

        // properties

        public List<TransportEvent> this[uint index_]
        {
            get
            {
                if (queue.ContainsKey(index_))
                {
                    return queue[index_];
                }

                throw new IndexOutOfRangeException("In EventQueue.this[index_]: index_ is out of range.");
            }
        }
    }
}
