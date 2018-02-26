package expression;

import domain.DomainException;
import domain.IDictionary;
import domain.IHeap;

public class ArithmeticExpression implements IExpression
{
	private char operator;
	private IExpression left,right;
	
	public ArithmeticExpression(char op, IExpression leftValue, IExpression rightValue)
	{
		operator=op;
		left=leftValue;
		right=rightValue;
	}

	@Override
	public int eval(IDictionary<String, Integer> symbolTable, IHeap<Integer,Integer> heap)
	{
		int left = this.left.eval(symbolTable,heap);
		int right = this.right.eval(symbolTable,heap);
		if(operator=='+')
			return left+right;
		if(operator=='-')
			return left-right;
		if(operator=='*')
			return left*right;
		if(operator=='/')
		{
			if(right==0)
				throw new DomainException("Division by 0!");
			return left/right;
		}
		throw new DomainException("Wrong operator!");
	}
	
	@Override
	public String toString()
	{
		return left.toString()+operator+right.toString();
	}

}
