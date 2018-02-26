package domain;

import java.util.List;

public class GuiPair 
{
	private Integer key;
	private List<Integer> list;
	//private String list;
	private Integer num;
	
	public GuiPair(Integer key, List<Integer> list, Integer num) 
	{
		this.key = key;
		this.list = list;
		this.num = num;
	}

	public Integer getKey() {
		return key;
	}

	public void setKey(Integer key) {
		this.key = key;
	}

	public String getList() {
		return list.toString();
	}

	public Integer getNum() {
		return num;
	}
	
	
	
	
}
