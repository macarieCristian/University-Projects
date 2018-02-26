package statement;

import java.io.BufferedReader;
import java.io.IOException;

import domain.DomainException;
import domain.PrgState;
import expression.IExpression;

public class CloseRFile implements IStatement 
{

	private IExpression exprFileId;
	
	public CloseRFile(IExpression fileid)
	{
		exprFileId = fileid;
	}
	
	private boolean exists(PrgState p, int id)
	{
		if(p.getFileTable().contains(id))
			return true;
		return false;
	}
	
	@Override
	public PrgState execute(PrgState ps) 
	{
		try 
		{
			int id = exprFileId.eval(ps.getSymbolTable(),ps.getHeap());
			if(!exists(ps,id))
				throw new DomainException("Cannot close a file which does not exist!");
			BufferedReader br = ps.getFileTable().getValue(id).getFileDescriptor();
			br.close();
			ps.getFileTable().remove(id);
		} 
		catch (IOException e) 
		{
			throw new DomainException(e.getMessage());
		}
		
		return null;
	}
	
	@Override
	public String toString()
	{
		return "Close("+exprFileId+")";
	}

}
