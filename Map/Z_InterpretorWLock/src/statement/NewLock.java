package statement;

import domain.LockIdGenerator;
import domain.PrgState;

public class NewLock implements IStatement 
{

	private String varName;
	
	public NewLock(String varName) 
	{
		this.varName = varName;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		int id;
		synchronized(ps.getLock())
		{
			id = LockIdGenerator.generateID();
			ps.getLock().add(id, -1);
		}
		
		if(!ps.getSymbolTable().contains(varName))
			ps.getSymbolTable().add(varName,id);
		else
			ps.getSymbolTable().update(varName,id);
		
		return null;
	}

	@Override
	public String toString() 
	{
		return "NewLock("+varName+")";
	}

}
