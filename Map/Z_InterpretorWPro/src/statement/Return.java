package statement;

import domain.PrgState;

public class Return implements IStatement 
{
	
	@Override
	public PrgState execute(PrgState ps) 
	{
		ps.getStackOfSym().pop();
		return null;
	}

	@Override
	public String toString() {
		return "Return";
	}
	
	

}
