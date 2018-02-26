package statement;

//import java.util.Random;

import domain.Dictionary;
import domain.ExeStack;
import domain.IDictionary;
import domain.IStack;
import domain.PrgState;

public class ForkStatement implements IStatement 
{
	private IStatement stmt;
	
	public ForkStatement(IStatement st)
	{
		stmt = st;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		IStack<IStatement> exeStack = new ExeStack<IStatement>();
		exeStack.push(stmt);
		IDictionary<String,Integer> symTable = new Dictionary<String,Integer>();
		for(String key : ps.getSymbolTable().getContent().keySet())
			symTable.add(key,ps.getSymbolTable().getValue(key));
		
		PrgState newPrgState = new PrgState(exeStack,symTable,ps.getOut(),ps.getFileTable(),ps.getHeap(),ps.getLock(),stmt);
//		Random rn = new Random();
//		int genId = rn.nextInt(100-10+1) + 10;
//		newPrgState.setId(genId);
		
		
		return newPrgState;
	}
	
	@Override
	public String toString()
	{
		return "Fork("+stmt+")";
	}

}
