package domain;

public interface IStack<T> 
{
	public T pop();
	public void push(T value);
	public boolean isEmpty();
	public T first();
	public Iterable<T> getAll();
}
