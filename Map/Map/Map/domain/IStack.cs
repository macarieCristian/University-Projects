using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.domain
{
    public interface IStack<T>
    {
        T pop();
        void push(T value);
        bool isEmpty();
        IEnumerable<T> getAll();
    }
}
