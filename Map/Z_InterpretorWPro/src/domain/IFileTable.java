package domain;

import java.util.Map;

public interface IFileTable<K,V> {
	
	public V getValue(K key);
	public boolean contains(K key);
	public void remove(K key);
	public void add(K key, V value);
	public boolean isEmpty();
	public Iterable<K> getAll();
	public Map<K, V> getContent();
	public void setContent(Map<K, V> map);
}
