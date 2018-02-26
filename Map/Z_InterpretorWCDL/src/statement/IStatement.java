package statement;

import domain.PrgState;

public interface IStatement 
{
	public PrgState execute(PrgState ps);
}
