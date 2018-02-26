package statement;

import java.io.BufferedReader;
import java.io.IOException;

import domain.DomainException;
import domain.PrgState;
import expression.IExpression;

public class ReadFile implements IStatement 
{
	private IExpression exprFileId;
	private String varName;
	
	public ReadFile(IExpression expr, String varn)
	{
		exprFileId = expr;
		varName = varn;
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
				throw new DomainException("The file does not exist!");
			BufferedReader br = ps.getFileTable().getValue(id).getFileDescriptor();
			int result;
			String line = br.readLine();
			if(line==null || line.equals(""))
				result = 0;
			else 
				result = Integer.parseInt(line.trim());
			if(ps.getSymbolTable().contains(varName))
				ps.getSymbolTable().update(varName,result);
			else
				ps.getSymbolTable().add(varName,result);
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
		return "ReadFile("+varName+")";
	}

}
