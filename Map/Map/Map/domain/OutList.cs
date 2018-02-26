using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.domain
{
    public class OutList<T> : ILis<T>
    {
        private List<T> list;

        public OutList()
        {
            list = new List<T>();
        }

        public void add(T value)
        {
            list.Add(value);
        }

        public bool contains(T value)
        {
            return list.Contains(value);
        }

        public IEnumerable<T> getAll()
        {
            return list.AsEnumerable<T>();
        }

        public T getElement(int index)
        {
            return list[index];
        }

        public bool isEmpty()
        {
            return list.Count == 0;
        }

        public void remove(T value)
        {
            list.Remove(value);
        }

        public int size()
        {
            return list.Count();
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            foreach (T el in list)
                sb.Append("" + el + ", ");
            return sb.ToString();
        }
    }
}
