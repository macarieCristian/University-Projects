package statement;

import domain.DomainException;
import domain.IDictionary;
import domain.IHeap;
import domain.PrgState;
import expression.IExpression;

public class WriteH implements IStatement 
{

	private String varName;
	private IExpression expr;
	
	public WriteH(String varName, IExpression expr) 
	{
		this.varName = varName;
		this.expr = expr;
	}

	@Override
	public PrgState execute(PrgState ps) 
	{
		IDictionary<String,Integer> sym = ps.getSymbolTable();
		IHeap<Integer,Integer> heap = ps.getHeap();
		if(!sym.contains(varName))
			throw new DomainException("Variable not found!");
		int addr = sym.getValue(varName);
		if(!heap.contains(addr))
			throw new DomainException("Invalid address!");
		int value = expr.eval(sym, heap);
		heap.update(addr, value);
		return null;
	}
	
	@Override
	public String toString() 
	{
		return "writeH("+varName+","+expr+")";
	}

}
