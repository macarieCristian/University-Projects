package repository;

import domain.PrgState;
import statement.IStatement;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository
{
	private List<PrgState> programList;
	private String logFile;
	
	public Repository(String filename)
	{
		programList = new ArrayList<PrgState>();
		logFile = filename;
	}


	@Override
	public void addPrgState(PrgState ps) 
	{
		programList.add(ps);
	}

	@Override
	public void logPrgStateExec(PrgState ps) 
	{
		try(PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(logFile,true))))
		{
			PrgState currentState = ps;
			pw.println("id: "+ps.getId());
			pw.println("ExeStack:");
			for(IStatement st : currentState.getExeStack().getAll())
				pw.println(st);
			pw.println("SymTable:");
			for(String key : currentState.getSymbolTable().getAll())
				pw.println(key+" -> "+currentState.getSymbolTable().getValue(key));
			pw.println("Out:");
			for(Integer el : currentState.getOut().getAll())
				pw.println(el);
			pw.println("FileTable:");
			for(Integer key: currentState.getFileTable().getAll())
				pw.println(key+" -> "+currentState.getFileTable().getValue(key));
			pw.println("Heap:");
			for(Integer key : currentState.getHeap().getAll())
				pw.println(key+" -> "+currentState.getHeap().getValue(key));
			pw.println("LatchTable:");
			for(Integer key : currentState.getLatch().getAll())
				pw.println(key+" -> "+currentState.getLatch().getValue(key));
			pw.println("---------------------------------------------------------------");
		} 
		catch (IOException e) 
		{
			throw new RepositoryException(e.getMessage());
		}
		
	}

	@Override
	public List<PrgState> getPrgList() 
	{
		return programList;
	}

	@Override
	public void setPrgList(List<PrgState> psList) 
	{
		programList = psList;
	}

}
