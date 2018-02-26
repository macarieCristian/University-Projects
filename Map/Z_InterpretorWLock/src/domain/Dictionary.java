package domain;

import java.util.HashMap;
import java.util.Map;


public class Dictionary<K,V> implements IDictionary<K,V>
{
	private HashMap<K,V> hm;
	
	public Dictionary()
	{
		hm = new HashMap<K,V>();
	}

	@Override
	public boolean contains(K key) 
	{
		return hm.containsKey(key);
	}

	@Override
	public V getValue(K key) 
	{
		return hm.get(key);
	}

	@Override
	public boolean isEmpty() 
	{
		return hm.isEmpty();
	}

	@Override
	public void remove(K key) 
	{
		hm.remove(key);
	}

	@Override
	public void update(K key, V value) 
	{
		hm.put(key, value);
	}

	@Override
	public void add(K key, V value) 
	{
		hm.put(key,value);
	}
	
	@Override
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		for(K key:hm.keySet())
			sb.append(" ("+key+","+hm.get(key)+") ");
		return sb.toString();
	}

	@Override
	public Iterable<K> getAll() 
	{
		return hm.keySet();
	}

	@Override
	public Map<K, V> getContent() 
	{
		return hm;
	}
}
