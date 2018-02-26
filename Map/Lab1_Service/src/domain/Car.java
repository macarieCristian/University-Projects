package domain;


public class Car extends Vehicle 
{
	private String color;
	
	public Car(String br, String dmg, int c, String col)
	{
		super(br,dmg,c);
		color=col;
	}
	
	public String getColor() {return color;}
	
	@Override
	public boolean equals(Object obj)
	{
		if(obj instanceof Car)
		{
			Car c = (Car)obj;
			return(this.brand.equals(c.brand) && this.damageLevel.equals(c.damageLevel) && this.cost==c.cost && this.color.equals(c.color));
		}
		return false;
	}
	
	@Override
	public String toString()
	{
		return "TYPE: CAR   Brand: "+brand+"   DmgLvl: "+damageLevel+"   Cost: "+cost+" Ron   Color: "+color;
	}
	
}
