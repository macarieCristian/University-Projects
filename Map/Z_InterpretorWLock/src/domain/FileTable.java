package domain;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

public class FileTable<K,V> implements IFileTable<K,V>
{
	private Map<K,V> hm;
	
	public FileTable()
	{
		hm = new ConcurrentHashMap<K,V>(); 
	}

	@Override
	public V getValue(K key) 
	{
		return hm.get(key);
	}

	@Override
	public boolean contains(K key) 
	{
		return hm.containsKey(key);
	}

	@Override
	public void remove(K key) 
	{
		hm.remove(key);
	}

	@Override
	public void add(K key, V value) 
	{
		hm.put(key, value);
	}

	@Override
	public boolean isEmpty() 
	{
		return hm.isEmpty();
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
	public Map<K,V> getContent() 
	{
		return hm;
	}

	@Override
	public void setContent(Map<K, V> map) 
	{
		hm = map;
	}
	
	

}
