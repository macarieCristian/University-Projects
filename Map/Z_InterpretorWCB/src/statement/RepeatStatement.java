package statement;

import domain.PrgState;
import expression.IExpression;
import expression.Neg;

public class RepeatStatement implements IStatement 
{

	private IStatement stm;
	private IExpression exp;
	
	
	
	public RepeatStatement(IStatement stm, IExpression exp) 
	{
		this.stm = stm;
		this.exp = exp;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		ps.getExeStack().push(new WhileStatement(new Neg(exp), stm));
		ps.getExeStack().push(stm);
		return null;
	}

	@Override
	public String toString() 
	{
		return "Repeat("+stm+"   until("+exp+")";
	}
	
	

}
