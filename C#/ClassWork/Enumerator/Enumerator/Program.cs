using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Enumerator
{
    public class PersonList : IEnumerable
    {
        private string[] _people;

        public PersonList(string[] list)
        {
            _people = new string[list.Length];
            list.CopyTo(_people, 0);
        }

        IEnumerator IEnumerable.GetEnumerator() // .begin()
        {
            return (IEnumerator)GetEnumerator();
        }

        public PeopleEnum GetEnumerator()
        {
            return new PeopleEnum(_people);
        }
    }

    public class PeopleEnum : IEnumerator
    {
        private string[] _people;

        // Enumerators are positioned before the first element
        // until the first MoveNext() call.
        int position = -1;

        public PeopleEnum(string[] list)
        {
            _people = list;
        }

        public bool MoveNext()
        {
            position++;
            return (position < _people.Length);
        }

        public void Reset()
        {
            position = -1;
        }

        object IEnumerator.Current
        {
            get
            {
                return Current;
            }
        }

        public string Current
        {
            get
            {
                try
                {
                    return _people[position];
                }
                catch (IndexOutOfRangeException)
                {
                    throw new InvalidOperationException();
                }
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            string[] people_names = new string[2]{"Andrew", "Anatoly"};
            PersonList people = new PersonList(people_names);

            foreach(var person in people)
            {
                Console.WriteLine(person);
            }
            
            Console.ReadKey();

        }
    }
}
