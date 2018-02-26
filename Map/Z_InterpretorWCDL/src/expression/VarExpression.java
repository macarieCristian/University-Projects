package expression;

import domain.DomainException;
import domain.IDictionary;
import domain.IHeap;

public class VarExpression implements IExpression
{
	private String varName;
	
	public VarExpression(String variableName)
	{
		varName = variableName;
	}
	
	@Override
	public int eval(IDictionary<String, Integer> symbolTable, IHeap<Integer,Integer> heap) 
	{
		if(symbolTable.contains(varName))
			return symbolTable.getValue(varName);
		throw new DomainException("Variable not found!");
	}
	
	@Override 
	public String toString()
	{
		return varName;
	}

}
