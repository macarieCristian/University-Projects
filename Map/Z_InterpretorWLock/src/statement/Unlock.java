package statement;

import domain.DomainException;
import domain.PrgState;

public class Unlock implements IStatement 
{

	private String varName;
	
	public Unlock(String varName) 
	{
		this.varName = varName;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		if(!ps.getSymbolTable().contains(varName))
			throw new DomainException("Variable not found!");
		
		int id = ps.getSymbolTable().getValue(varName);
		if(!ps.getLock().contains(id))
			throw new DomainException("This lock does not exists!");
		
		synchronized(ps.getLock())
		{
			if(ps.getLock().getValue(id) == ps.getId())
				ps.getLock().update(id,-1);
		}
		
		return null;
	}

	@Override
	public String toString() 
	{
		return "Unlock("+varName+")";
	}
	
	

}
