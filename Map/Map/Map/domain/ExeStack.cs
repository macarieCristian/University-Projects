using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.domain
{
    public class ExeStack<T> : IStack<T>
    {
        private Stack<T> stack;

        public ExeStack()
        {
            stack = new Stack<T>();
        }

        public IEnumerable<T> getAll()
        {
            return stack.AsEnumerable<T>();
        }

        public bool isEmpty()
        {
            return stack.Count == 0;
        }

        public T pop()
        {
            return stack.Pop();
        }

        public void push(T value)
        {
            stack.Push(value);
        }

        public override String ToString()
        {
            StringBuilder sb = new StringBuilder();
            foreach(T x in stack)
            {
                sb.Append(x + ", ");
            }
            return sb.ToString();
        }
    }
}
