package statement;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import domain.DomainException;
import domain.FileData;
import domain.FileIDGenerator;
import domain.IFileTable;
import domain.PrgState;

public class OpenRFile implements IStatement 
{
	
	private String varFile;
	private String fileName;
	
	public OpenRFile(String varf, String fn)
	{
		varFile = varf;
		fileName = fn;
	}
	
	private boolean exists(PrgState p, String fileName)
	{
		IFileTable<Integer,FileData> ft = p.getFileTable();
		for(Integer key : ft.getAll())
		{
			if(ft.getValue(key).getFileName().equals(fileName))
				return true;
		}
		return false;
	}
	
	@Override
	public PrgState execute(PrgState ps) 
	{
		if(exists(ps,fileName))
			throw new DomainException("The file: "+fileName+" is already open!");
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(fileName));
			
			FileData data = new FileData(fileName,br);
			int id = FileIDGenerator.generateID();
			ps.getFileTable().add(id,data);
			if(ps.getSymbolTable().contains(varFile))
				ps.getSymbolTable().update(varFile,id);
			else
				ps.getSymbolTable().add(varFile,id);
			
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
		return "Openfile("+varFile+","+fileName+") ";
	}

}
