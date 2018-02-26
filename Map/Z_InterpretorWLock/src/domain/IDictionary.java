package domain;

import java.util.Map;

public interface IDictionary<K,V> 
{
	public boolean contains(K key);
	public V getValue(K key);
	public boolean isEmpty();
	public void remove(K key);
	public void update(K key, V value);
	public void add(K key, V value);
	public Iterable<K> getAll();
	public Map<K,V> getContent();
}
