package statement;

import domain.DomainException;
import domain.PrgState;

public class Await implements IStatement 
{

	private String varName;
	
	public Await(String varName) 
	{
		this.varName = varName;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		if(!ps.getSymbolTable().contains(varName))
			throw new DomainException("Variable not found!");
		int id = ps.getSymbolTable().getValue(varName);
		if(!ps.getLatch().contains(id))
			throw new DomainException("Latch does not exists!");
		synchronized(ps.getLatch())
		{
			if(ps.getLatch().getValue(id) != 0)
				ps.getExeStack().push(this);
		}
		return null;
	}

	@Override
	public String toString() 
	{
		return "Await("+varName+")";
	}
	
	

}
