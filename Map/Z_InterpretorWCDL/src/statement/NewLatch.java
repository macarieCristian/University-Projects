package statement;

import domain.LatchIdGenerator;
import domain.PrgState;
import expression.IExpression;

public class NewLatch implements IStatement 
{

	private String varName;
	private IExpression exp;
	
	public NewLatch(String varName, IExpression exp) 
	{
		this.varName = varName;
		this.exp = exp;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		int res = exp.eval(ps.getSymbolTable(),ps.getHeap());
		int id;
		synchronized(ps.getLatch())
		{
			id = LatchIdGenerator.generateID();
			ps.getLatch().add(id,res);
		}
		if(ps.getSymbolTable().contains(varName))
			ps.getSymbolTable().update(varName,id);
		else
			ps.getSymbolTable().add(varName,id);
		return null;
	}

	@Override
	public String toString() 
	{
		return "NewLatch("+varName+","+exp+")";
	}
	
	

}
