package statement;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

import domain.Dictionary;
import domain.DomainException;
import domain.IDictionary;
import domain.PrgState;
import expression.IExpression;

public class Call implements IStatement 
{

	private List<IExpression> list;
	private String name;
	
	public Call(String nam, IExpression... exprs)
	{
		list = new ArrayList<IExpression>();
		for(int i=0;i<exprs.length;i++)
			list.add(exprs[i]);
		
		name = nam;
	}
	
	@Override
	public PrgState execute(PrgState ps) 
	{
		if(!ps.getProc().contains(name))
			throw new DomainException("Proc not found!");
		List<String> varNames = ps.getProc().getValue(name).getListOfVars();
		List<Integer> nums = list.stream().map(ex->ex.eval(ps.getStackOfSym().first(), ps.getHeap()))
				.collect(Collectors.toList());
		IDictionary<String,Integer> symb = new Dictionary<String,Integer>();
		for(int i=0;i<varNames.size();i++)
			symb.add(varNames.get(i), nums.get(i));
		ps.getStackOfSym().push(symb);
		
		ps.getExeStack().push(new Return());
		ps.getExeStack().push(ps.getProc().getValue(name).getStm());
		
		return null;
	}

	
	@Override
	public String toString() {
		return "Call "+name+list.toString();
	}
	
	

}
