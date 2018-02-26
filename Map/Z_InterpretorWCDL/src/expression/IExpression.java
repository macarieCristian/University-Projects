package expression;

import domain.IDictionary;
import domain.IHeap;

public interface IExpression 
{
	public int eval(IDictionary<String,Integer> symbolTable, IHeap<Integer,Integer> heap);
}
