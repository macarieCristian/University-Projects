package expression;

import domain.IDictionary;
import domain.IHeap;

public class ConstExpression implements IExpression
{

	private int constant;
	
	public ConstExpression(int value)
	{
		constant=value;
	}
	
	@Override
	public int eval(IDictionary<String, Integer> symbolTable, IHeap<Integer,Integer> heap) 
	{
		return constant;
	}
	
	@Override 
	public String toString()
	{
		return ""+constant;
	}

}
