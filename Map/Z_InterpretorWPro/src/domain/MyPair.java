package domain;

import java.util.ArrayList;
import java.util.List;

import statement.IStatement;

public class MyPair 
{

	private List<String> listOfVars;
	private IStatement stm;
	public MyPair(IStatement stm) {
		super();
		this.listOfVars = new ArrayList<String>();
		this.stm = stm;
	}
	public List<String> getListOfVars() {
		return listOfVars;
	}
	public void setListOfVars(List<String> listOfVars) {
		this.listOfVars = listOfVars;
	}
	public IStatement getStm() {
		return stm;
	}
	public void setStm(IStatement stm) {
		this.stm = stm;
	}
	@Override
	public String toString() 
	{
		return "  "+listOfVars.toString()+"  "+stm;
	}
	
	
}
