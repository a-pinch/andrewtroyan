using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Transport
{
    // delegate for events

    delegate void TransportEvent(uint time);

    // provides storage for events (key - time, value - events at this time)

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
        
        // adds new event at certain time (marked as index)
        public void Add(uint index, TransportEvent transportEvent)
        {
            if (queue.ContainsKey(index) == false)
            {
                queue[index] = new List<TransportEvent>();
            }

            queue[index].Add(transportEvent);
        } 

        // removes all events (if there are any of them) at given time
        public void Remove(uint index)
        {
            if (queue.ContainsKey(index))
            {
                queue[index].Clear();
                queue.Remove(index);
            }
        }

        // determines if there are events at given time
        public bool ContainsKey(uint index_)
        {
            return queue.ContainsKey(index_);
        }

        // indexer 

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
