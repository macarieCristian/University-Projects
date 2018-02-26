package domain;

public class ThreadIDGenerator 
{
	private static int id = 0;
	public static int generateID()
	{
		return id++;
	}
}
