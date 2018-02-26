package domain;

public class Motorcycle extends Vehicle
{

	private String type;
	
	public Motorcycle(String br, String dmg, int c, String typ)
	{
		super(br,dmg,c);
		type=typ;
	}
	
	public String getType() {return type;}
	
	@Override
	public boolean equals(Object obj)
	{
		if(obj instanceof Motorcycle)
		{
			Motorcycle m = (Motorcycle)obj;
			return (m.brand.equals(this.brand) && m.damageLevel.equals(this.damageLevel) && m.cost == this.cost && m.type.equals(this.type));
		}
		return false;
	}
	
	@Override
	public String toString()
	{
		return "TYPE: MOTORCYCLE   Brand: "+brand+"   DmgLvl: "+damageLevel+"   Cost: "+cost+" Ron   Type: "+type;
	}
}
