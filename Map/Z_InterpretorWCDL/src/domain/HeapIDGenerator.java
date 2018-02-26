package domain;

public class HeapIDGenerator 
{
	private static int id = 0;
	public static int generateID()
	{
		return id++;
	}
}
