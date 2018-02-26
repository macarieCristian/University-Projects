package statement;

import domain.DomainException;
import domain.MyPair;
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
		if(!ps.getCyclicBarrier().contains(id))
			throw new DomainException("Barrier not found!");
		
		synchronized(ps.getCyclicBarrier())
		{
			MyPair mp = ps.getCyclicBarrier().getValue(id);
			if(mp.getList().size()==mp.getNum()) {}
			else if(mp.getList().contains(ps.getId()))
				ps.getExeStack().push(this);
			else if(!mp.getList().contains(ps.getId()))
				{
					mp.getList().add(ps.getId());
					ps.getExeStack().push(this);
				}
		}
		
		return null;
	}

	@Override
	public String toString() 
	{
		return "Await("+varName+")";
	}
	
	

}
