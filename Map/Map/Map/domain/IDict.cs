using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.domain
{
    public interface IDict<K,V>
    {
        Dictionary<K,V> Dict {get;}
        bool contains(K key);
        V getValue(K key);
        bool isEmpty();
        void remove(K key);
        void update(K key, V value);
        void add(K key, V value);
        IEnumerable<K> getAll();
    }
}
