package repository;
import domain.Vehicle;
import repository.Repository;

public class RepositoryMemoryImplementation implements Repository
{
	private Vehicle[] arry;
	private int size;
	
	public RepositoryMemoryImplementation(int len)
	{
		arry = new Vehicle[len];
		size=0;
	}
	
	public int getSize() {return this.size;}
	public void setSize(int a) {size=a;}

	@Override
	public void addVehicle(Vehicle v) throws Exception {
		int x = find(v);
		if(x!=-1)
		{
			throw new Exception("\nThe entity already exists!");
		}
		if(size==arry.length)
			resize();
		arry[size++]=v;
	}

	private void resize() 
	{
		Vehicle[] cpy = new Vehicle[size*2];
		for(int i=0;i<size;i++)
			cpy[i]=arry[i];
		arry = cpy;
	}

	@Override
	public void removeVehicle(Vehicle v) throws Exception {
		int x = find(v);
		if(x==-1)
			throw new Exception("\nThe entity does not exists!");
		arry[x]=arry[size];
		size--;
	}

	@Override
	public Vehicle[] getRepo() {
		Vehicle[] cpy = new Vehicle[size];
		for(int i=0;i<size;i++)
			cpy[i]=arry[i];
		return cpy;
	}

	@Override
	public int find(Vehicle v){
		for(int i=0;i<size;i++)
		{
			if(v.equals(arry[i]))
				return i;
		}
		return -1;
	}

}
