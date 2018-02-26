package expression;

import domain.DomainException;
import domain.IDictionary;
import domain.IHeap;

public class BooleanExpression implements IExpression 
{
	private String operator;
	private IExpression expr1;
	private IExpression expr2;
	
	public BooleanExpression(String operator, IExpression expr1, IExpression expr2) 
	{
		this.operator = operator;
		this.expr1 = expr1;
		this.expr2 = expr2;
	}

	@Override
	public int eval(IDictionary<String, Integer> symbolTable, IHeap<Integer, Integer> heap) 
	{
		int f = expr1.eval(symbolTable, heap);
		int s = expr2.eval(symbolTable, heap);
		if(operator.equals("<"))
			return f<s?1:0;
		if(operator.equals("<="))
			return f<=s?1:0;
		if(operator.equals("=="))
			return f==s?1:0;
		if(operator.equals("!="))
			return f!=s?1:0;
		if(operator.equals(">"))
			return f>s?1:0;
		if(operator.equals(">="))
			return f>=s?1:0;
		throw new DomainException("Wrong operator!");
	}

	@Override
	public String toString() 
	{
		return expr1+operator+expr2;
	}
	
	

}
