using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.domain
{
    public interface ILis<T>
    {
        void add(T value);
        void remove(T value);
        bool isEmpty();
        bool contains(T value);
        T getElement(int index);
        int size();
        IEnumerable<T> getAll();
    }
}
