package statement;

import domain.PrgState;
import expression.IExpression;

public class WhileStatement implements IStatement 
{

	private IExpression condition;
	private IStatement stmt;
	
	
	public WhileStatement(IExpression condition, IStatement stmt) 
	{
		this.condition = condition;
		this.stmt = stmt;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		if(condition.eval(ps.getStackOfSym().first(), ps.getHeap())!=0)
		{
			ps.getExeStack().push(this);
			ps.getExeStack().push(stmt);
		}
		return null;
	}

	@Override
	public String toString() 
	{
		return "While("+condition+") do "+stmt;
	}
	
	

}
