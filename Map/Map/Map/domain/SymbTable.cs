using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Map.domain
{
    public class SymbTable<K, V> : IDict<K, V>
    {
        private Dictionary<K, V> dict;
        public SymbTable()
        {
            dict = new Dictionary<K, V>();
        }

        public Dictionary<K, V> Dict
        {
            get
            {
                return dict;
            }
        }

        public void add(K key, V value)
        {
            dict.Add(key, value);
        }

        public bool contains(K key)
        {
            return dict.ContainsKey(key);
        }

        public IEnumerable<K> getAll()
        {
            return dict.Keys;
        }

        public V getValue(K key)
        {
            return dict[key];
        }

        public bool isEmpty()
        {
            return dict.Count == 0;
        }

        public void remove(K key)
        {
            dict.Remove(key);
        }

        public void update(K key, V value)
        {
            dict[key] = value;
        }

        public override string ToString()
        {
            StringBuilder sb = new StringBuilder();
            foreach (K key in dict.Keys)
                sb.Append(" (" + key + "," + dict[key] + ") ");
            return sb.ToString();
        }
    }
}
