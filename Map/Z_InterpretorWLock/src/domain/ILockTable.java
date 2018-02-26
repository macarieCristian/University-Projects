package domain;

public interface ILockTable<K,V> 
{
	public void add(K key, V value);
	public void update(K key, V value);
	public boolean contains(K key);
	public V getValue(K key);
	public boolean isEmpty();
	public void remove(K key);
	public Iterable<K> getAll();
}
