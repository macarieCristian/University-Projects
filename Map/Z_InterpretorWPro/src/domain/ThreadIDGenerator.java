package domain;

public class ThreadIDGenerator 
{
	private static int id = 1;
	public static int generateID()
	{
		return id++;
	}
}
