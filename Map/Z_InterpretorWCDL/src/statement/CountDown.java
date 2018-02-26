package statement;

import domain.DomainException;
import domain.PrgState;
import expression.ConstExpression;

public class CountDown implements IStatement 
{
	private String varName;
	
	public CountDown(String varName) 
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
			if(ps.getLatch().getValue(id)>0)
			{
				ps.getLatch().update(id, ps.getLatch().getValue(id)-1);
				//ps.getOut().add(ps.getId());
			}
			ps.getOut().add(ps.getId());
		}
		return null;
	}

	@Override
	public String toString() 
	{
		return "CountDown("+varName+")";
	}
	
	

}
