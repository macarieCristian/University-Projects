package domain;

import java.util.ArrayList;

public class OutList<T> implements IList<T>
{
	private ArrayList<T> al;
	
	public OutList()
	{
		al = new ArrayList<T>();
	}

	@Override
	public void add(T value) 
	{
		synchronized(this)
		{
			al.add(value);
		}
	}

	@Override
	public void remove(T value) 
	{
		synchronized(this)
		{
			al.remove(value);
		}
	}

	@Override
	public void remove(int index) 
	{
		synchronized(this)
		{
			al.remove(index);
		}
	}

	@Override
	public boolean isEmpty() 
	{
		synchronized(this)
		{
			return al.isEmpty();
		}
	}

	@Override
	public boolean contains(T value) 
	{
		synchronized(this)
		{
			return al.contains(value);
		}
	}

	@Override
	public T getElement(int index) 
	{
		synchronized(this)
		{
			return al.get(index);
		}
	}

	@Override
	public int size() 
	{
		synchronized(this)
		{
			return al.size();
		}
	}
	
	@Override
	public String toString()
	{
		synchronized(this)
		{
			StringBuffer sb = new StringBuffer();
			for(T e: al)
				sb.append(""+e+", ");
			return sb.toString();
		}
	}

	@Override
	public Iterable<T> getAll() 
	{
		synchronized(this)
		{
			return al;
		}
	}
	
	
}
