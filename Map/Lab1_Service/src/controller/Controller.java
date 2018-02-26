package controller;

import domain.Vehicle;
import repository.Repository;
import repository.RepositoryMemoryImplementation;

public class Controller 
{
	private Repository repo;
	
	public Controller(Repository r)
	{
		repo=r;
	}
	
	public Repository filterByPrice(int sum) throws Exception
	{
		Repository r = new RepositoryMemoryImplementation(repo.getSize());
		Vehicle[] now = repo.getRepo();
		for(int i=0;i<now.length;i++)
		{
			if(now[i].getCost()>sum)
			{
				r.addVehicle(now[i]);
			}
		}
		if(r.getSize()==0)
			throw new Exception("No items match this criteria!");
		
		return r;
	}
	
	public Repository getRepository() {return repo;}
	
	
}
