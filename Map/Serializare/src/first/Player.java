package first;

import java.io.Serializable;

public class Player implements Serializable
{
	private String name;
	private int salary;
	private String pozition;
	
	public Player(String name, int salary, String pozition) 
	{
		this.name = name;
		this.salary = salary;
		this.pozition = pozition;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getSalary() {
		return salary;
	}

	public void setSalary(int salary) {
		this.salary = salary;
	}

	public String getPozition() {
		return pozition;
	}

	public void setPozition(String pozition) {
		this.pozition = pozition;
	}

	@Override
	public String toString() {
		return name+"   "+salary+"   "+pozition;
	}
	
	
	
	
}
