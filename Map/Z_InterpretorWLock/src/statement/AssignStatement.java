package statement;

import domain.IDictionary;
import domain.IHeap;
import domain.PrgState;
import expression.IExpression;

public class AssignStatement implements IStatement
{
	private String varName;
	private IExpression expr;
	
	public AssignStatement(String vn, IExpression e)
	{
		varName = vn;
		expr = e;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		IDictionary<String,Integer> symbTab = ps.getSymbolTable();
		IHeap<Integer,Integer> heap = ps.getHeap();
		int result = expr.eval(symbTab,heap);
		if(symbTab.contains(varName))
			symbTab.update(varName, result);
		else
			symbTab.add(varName, result);     //!
		return null;
	}
	
	@Override
	public String toString()
	{
		return varName+"="+expr;
	}
}
