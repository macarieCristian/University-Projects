package domain;

public class BarrierIdGenerator 
{
	private static int id = 0;
	public static int generateID()
	{
		return id++;
	}
}
