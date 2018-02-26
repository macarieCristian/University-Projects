package domain;

public interface IList<T> 
{
	public void add(T value);
	public void remove(T value);
	public void remove(int index);
	public boolean isEmpty();
	public boolean contains(T value);
	public T getElement(int index);
	public int size();
	public Iterable<T> getAll();
}
