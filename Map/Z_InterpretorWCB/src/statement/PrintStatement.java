package statement;

import domain.IDictionary;
import domain.IHeap;
import domain.IList;
import domain.PrgState;
import expression.IExpression;

public class PrintStatement implements IStatement
{
	private IExpression expr;
	
	public PrintStatement(IExpression e)
	{
		expr = e;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		IList<Integer> list = ps.getOut();
		IDictionary<String,Integer> dict = ps.getSymbolTable();
		IHeap<Integer,Integer> heap = ps.getHeap();
		int result = expr.eval(dict,heap);
		list.add(result);
		return null;
	}
	
	@Override
	public String toString()
	{
		return "Print("+expr+")";
	}

}
