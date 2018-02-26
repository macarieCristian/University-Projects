package statement;

import domain.HeapIDGenerator;
import domain.IDictionary;
import domain.IHeap;
import domain.PrgState;
import expression.IExpression;

public class NewH implements IStatement 
{
	private String varName;
	private IExpression expr;
	
	public NewH(String varName, IExpression expr) 
	{
		this.varName = varName;
		this.expr = expr;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		IDictionary<String,Integer> symTab = ps.getStackOfSym().first();
		IHeap<Integer,Integer> heap = ps.getHeap();
		int res = expr.eval(symTab,heap);
		int id = HeapIDGenerator.generateID();
		if(symTab.contains(varName))
			symTab.update(varName,id);
		else
			symTab.add(varName,id);
		heap.add(id,res);
		return null;
	}

	@Override
	public String toString() 
	{
		return "new("+varName+","+expr+")";
	}
	
	

}
