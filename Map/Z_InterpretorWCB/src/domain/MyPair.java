package domain;

import java.util.List;
import java.util.Vector;

public class MyPair 
{
	private List<Integer> list;
	private Integer num;
	
	public MyPair(Integer num) 
	{
		this.list = new Vector<Integer>();
		this.num = num;
	}

	public List<Integer> getList() {
		return list;
	}

	public void setList(List<Integer> list) {
		this.list = list;
	}

	public Integer getNum() {
		return num;
	}

	public void setNum(Integer num) {
		this.num = num;
	}

	@Override
	public String toString() 
	{
		StringBuffer sb = new StringBuffer();
		sb.append(" "+list.toString()+" , ");
		sb.append(num);
		return sb.toString();
	}
	
	
	
	
}
