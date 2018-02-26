package domain;

public class FileIDGenerator 
{
	private static int id = 0;
	public static int generateID()
	{
		return id++;
	}
}
