package statement;

import java.util.ArrayList;

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
		ArrayList<IDictionary<String,Integer>> aux = new ArrayList<IDictionary<String,Integer>>();
		IStack<IStatement> exeStack = new ExeStack<IStatement>();
		exeStack.push(stmt);
		IStack<IDictionary<String,Integer>> symTable = new ExeStack<IDictionary<String,Integer>>();
//		IDictionary<String,Integer> dict = new Dictionary<String,Integer>();
//		for(String key : ps.getStackOfSym().first().getAll())
//			dict.add(key, ps.getStackOfSym().first().getValue(key));
		for(IDictionary<String,Integer> sym : ps.getStackOfSym().getAll())
		{
			IDictionary<String,Integer> dict = new Dictionary<String,Integer>();
			for(String key : sym.getAll())
				dict.add(key, ps.getStackOfSym().first().getValue(key));
			aux.add(dict);
		}
			
		for(int i=aux.size()-1;i>=0;i--)
			symTable.push(aux.get(i));
//		symTable.push(dict);
		
		PrgState newPrgState = new PrgState(exeStack,symTable,ps.getOut(),ps.getFileTable(),ps.getHeap(),ps.getProc(),stmt);
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
