package statement;

import domain.IDictionary;
import domain.IHeap;
import domain.IStack;
import domain.PrgState;
import expression.IExpression;

public class IfStatement implements IStatement
{
	private IExpression condition;
	private IStatement trueStatement,falseStatement;
	
	public IfStatement(IExpression e, IStatement trueS, IStatement falseS)
	{
		condition = e;
		trueStatement = trueS;
		falseStatement = falseS;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		IStack<IStatement> stack = ps.getExeStack();
		IDictionary<String,Integer> dict = ps.getStackOfSym().first();
		IHeap<Integer,Integer> heap = ps.getHeap();
		if(condition.eval(dict,heap)==0)
		{
			stack.push(falseStatement);
		}
		else
		{
			stack.push(trueStatement);
		}
		return null;
	}
	
	@Override
	public String toString()
	{
		return "if "+condition+" then "+trueStatement+" else "+falseStatement;
	}
	
	
	
	
}
