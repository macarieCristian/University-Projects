package statement;

import domain.PrgState;
import expression.ConstExpression;
import expression.IExpression;

public class Sleep implements IStatement 
{

	private IExpression number;
	
	public Sleep(IExpression num) 
	{
		number = num;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		int num = number.eval(ps.getStackOfSym().first(),ps.getHeap());
		if(num > 0)
		{
			ps.getExeStack().push(new Sleep(new ConstExpression(num-1)));
		}
		return null;
	}

	@Override
	public String toString() 
	{
		return "Sleep("+number+")";
	}
	
	

}
