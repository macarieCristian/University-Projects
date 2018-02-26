package statement;

import domain.PrgState;
import expression.IExpression;

public class ForStatement implements IStatement 
{
	
	private IStatement init;
	private IExpression cond;
	private IStatement stmt;
	private IStatement step;
	
	
	public ForStatement(IStatement init, IExpression cond, IStatement step, IStatement stmt) {
		this.init = init;
		this.cond = cond;
		this.step = step;
		this.stmt = stmt;
	}


	@Override
	public PrgState execute(PrgState ps) 
	{
		ps.getExeStack().push(new WhileStatement(cond,new CompStatement(stmt,step)));
		ps.getExeStack().push(init);
		return null;
	}


	@Override
	public String toString() 
	{
		return "For("+init+";"+cond+";"+step+")"+stmt;
	}
	
	

}
