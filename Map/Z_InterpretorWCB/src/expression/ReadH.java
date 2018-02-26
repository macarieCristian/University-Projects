package expression;

import domain.DomainException;
import domain.IDictionary;
import domain.IHeap;

public class ReadH implements IExpression 
{
	private String varName;
	
	

	public ReadH(String varName) 
	{
		this.varName = varName;
	}

	@Override
	public int eval(IDictionary<String, Integer> symbolTable, IHeap<Integer, Integer> heap) 
	{
		if(!symbolTable.contains(varName))
			throw new DomainException("Variable "+varName+" is unknown! (in symbTab)");
		int addr = symbolTable.getValue(varName);
		if(!heap.contains(addr))
			throw new DomainException("The address "+addr+" does not exists in heap!");
		return heap.getValue(addr);
	}

	@Override
	public String toString() 
	{
		return "readH("+varName+")";
	}
	
	

}
