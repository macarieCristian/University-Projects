package domain;

public abstract class Vehicle 
{
	protected String brand;
	protected String damageLevel;
	protected int cost;
	
	public Vehicle(String br, String dmg, int c)
	{
		brand=br;
		damageLevel=dmg;
		cost=c;
	}
	
	public String getBrand() {return brand;}
	public String getDamageLevel() {return damageLevel;}
	public int getCost() {return cost;}
	
}
