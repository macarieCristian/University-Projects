package domain;

public class Truck extends Vehicle
{

	private int weight;
	
	public Truck(String br, String dmg, int c, int weigh)
	{
		super(br,dmg,c);
		weight = weigh;
	}
	
	public int getWeight() {return weight;}
	
	@Override
	public boolean equals(Object obj)
	{
		if(obj instanceof Truck)
		{
			Truck t = (Truck)obj;
			return (t.brand.equals(this.brand) && t.damageLevel.equals(this.damageLevel) && t.cost == this.cost && t.weight == this.weight);
		}
		return false;
	}
	
	@Override
	public String toString()
	{
		return "TYPE: TRUCK   Brand: "+brand+"   DmgLvl: "+damageLevel+"   Cost: "+cost+" Ron   Weight: "+weight+" Kg";
	}
}
