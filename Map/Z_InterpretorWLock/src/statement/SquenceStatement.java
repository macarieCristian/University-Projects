package statement;

import java.util.ArrayList;
import java.util.List;

import domain.PrgState;

public class SquenceStatement implements IStatement {

	private List<IStatement> aux;
	
	public SquenceStatement(IStatement... stms)
	{
		aux = new ArrayList<IStatement>();
		for(IStatement st : stms)
			aux.add(st);
	}
	
	@Override
	public PrgState execute(PrgState ps) 
	{

		for(int i = aux.size()-1;i>=0;i--)
			ps.getExeStack().push(aux.get(i));
		
		return null;
	}

	@Override
	public String toString() 
	{
		StringBuffer sb = new StringBuffer();
		sb.append("(");
		for(IStatement s : aux)
		{
			sb.append(s);
			sb.append(";");
		}
		sb.append(")");
		return sb.toString();
	}
	
	

}
