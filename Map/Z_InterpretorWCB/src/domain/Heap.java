package domain;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class Heap<K,V> implements IHeap<K, V> 
{
	private Map<K,V> heap;
	
	public Heap()
	{
		heap = new ConcurrentHashMap<K,V>();
	}
	
	@Override
	public void add(K key, V value) 
	{
		heap.put(key, value);
	}

	@Override
	public void update(K key, V value) 
	{
		heap.put(key, value);
	}

	@Override
	public boolean contains(K key) 
	{
		return heap.containsKey(key);
	}

	@Override
	public V getValue(K key) 
	{
		return heap.get(key);
	}

	@Override
	public boolean isEmpty() 
	{
		return heap.isEmpty();
	}

	@Override
	public void remove(K key) 
	{
		heap.remove(key);
	}

	@Override
	public Iterable<K> getAll() 
	{
		return heap.keySet();
	}
	
	@Override
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		for(K key:heap.keySet())
			sb.append(" ("+key+","+heap.get(key)+") ");
		return sb.toString();
	}

	@Override
	public Map<K,V> getContent() 
	{
		return heap;
	}

	@Override
	public void setContent(Map<K, V> map) 
	{
		heap = map;
	}

}
