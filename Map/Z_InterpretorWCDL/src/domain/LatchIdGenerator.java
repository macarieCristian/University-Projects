package domain;

public class LatchIdGenerator 
{
	private static int id = 0;
	public static int generateID()
	{
		return id++;
	}
}
