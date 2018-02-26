package domain;

import java.util.List;

import expression.IExpression;
import statement.IStatement;

public class GuiPair {
	
	private String name;
	private List<String> list;
	private IStatement stm;
	public GuiPair(String name, List<String> list, IStatement stm) {
		super();
		this.name = name;
		this.list = list;
		this.stm = stm;
	}
	public String getName() {
		return name+list.toString();
	}
	public void setName(String name) {
		this.name = name;
	}
	
	public IStatement getStm() {
		return stm;
	}
	public void setStm(IStatement stm) {
		this.stm = stm;
	}
	
	

}
