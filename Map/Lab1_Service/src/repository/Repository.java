package repository;

import domain.Vehicle;

public interface Repository 
{
	public void addVehicle(Vehicle v) throws Exception;
	public void removeVehicle(Vehicle v) throws Exception;
	public Vehicle[] getRepo();
	public int find(Vehicle v);
	public int getSize();
	public void setSize(int a);
}
