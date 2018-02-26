package domain;

public class LockIdGenerator 
{
	private static int id = 0;
	public static int generateID()
	{
		return id++;
	}
}
