package expression;

import domain.IDictionary;
import domain.IHeap;

public class Neg implements IExpression {

	private IExpression exp;
	
	public Neg(IExpression exp) 
	{
		this.exp = exp;
	}

	@Override
	public int eval(IDictionary<String, Integer> symbolTable, IHeap<Integer, Integer> heap) {

		int res = exp.eval(symbolTable, heap);
		return 1-res;
	}

	@Override
	public String toString() {
		return "!"+exp;
	}
	
	

}
