package domain;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class LockTable<K,V> implements ILockTable<K, V> {

private Map<K,V> table;
	
	public LockTable()
	{
		table = new ConcurrentHashMap<K,V>();
	}
	
	@Override
	public void add(K key, V value) 
	{
		table.put(key, value);
	}

	@Override
	public void update(K key, V value) 
	{
		table.put(key, value);
	}

	@Override
	public boolean contains(K key) 
	{
		return table.containsKey(key);
	}

	@Override
	public V getValue(K key) 
	{
		return table.get(key);
	}

	@Override
	public boolean isEmpty() 
	{
		return table.isEmpty();
	}

	@Override
	public void remove(K key) 
	{
		table.remove(key);
	}

	@Override
	public Iterable<K> getAll() 
	{
		return table.keySet();
	}
	
	@Override
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		for(K key:table.keySet())
			sb.append(" ("+key+","+table.get(key)+") ");
		return sb.toString();
	}

}
