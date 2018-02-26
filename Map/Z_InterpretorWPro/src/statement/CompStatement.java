package statement;

import domain.IStack;
import domain.PrgState;

public class CompStatement implements IStatement
{
	private IStatement s1,s2;
	
	public CompStatement(IStatement st1, IStatement st2)
	{
		s1=st1;
		s2=st2;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		IStack<IStatement> stack = ps.getExeStack();
		stack.push(s2);
		stack.push(s1);
		return null;
	}
	
	@Override
	public String toString()
	{
		return "("+s1+" ; "+s2+")";
	}
	
	

}
