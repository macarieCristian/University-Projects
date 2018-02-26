package statement;

import domain.BarrierIdGenerator;
import domain.MyPair;
import domain.PrgState;
import expression.IExpression;

public class NewBarrier implements IStatement 
{

	private String varName;
	private IExpression exp;
	
	public NewBarrier(String varName, IExpression exp) 
	{
		this.varName = varName;
		this.exp = exp;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		int val = exp.eval(ps.getSymbolTable(), ps.getHeap());
		int id;
		synchronized(ps.getCyclicBarrier())
		{
			id = BarrierIdGenerator.generateID();
			ps.getCyclicBarrier().add(id, new MyPair(val));
		}
		if(ps.getSymbolTable().contains(varName))
			ps.getSymbolTable().update(varName, id);
		else
			ps.getSymbolTable().add(varName, id);
		return null;
	}

	@Override
	public String toString() 
	{
		return "NewBarrier("+varName+","+exp+")";
	}
	
	
	

}
