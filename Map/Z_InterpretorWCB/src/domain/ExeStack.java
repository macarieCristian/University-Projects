package domain;

import java.util.ArrayDeque;
import java.util.Deque;

public class ExeStack<T> implements IStack<T>
{
	private Deque<T> sk;
	
	public ExeStack()
	{
		sk  = new ArrayDeque<T>();
	}

	@Override
	public T pop() 
	{
		return sk.pop();
	}

	@Override
	public void push(T value) 
	{
		sk.push(value);
	}

	@Override
	public boolean isEmpty() 
	{
		return sk.isEmpty();
	}

	@Override
	public T first() 
	{
		return sk.peek();
	}
	
	@Override
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		for(T e : sk)
			sb.append(""+e+", ");
		return sb.toString();
	}

	@Override
	public Iterable<T> getAll() 
	{
		return sk;
	}


}
