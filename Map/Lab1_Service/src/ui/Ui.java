package ui;
import controller.Controller;
import domain.Car;
import domain.Motorcycle;
import domain.Truck;
import domain.Vehicle;
import repository.Repository;
import repository.RepositoryMemoryImplementation;

public class Ui 
{
	private static void printRepo(Repository r)
	{
		for(Vehicle v:r.getRepo())
		{
			System.out.println(v);
		}
	}
	
	public static void main(String[] args)
	{
		try {
			Repository r = new RepositoryMemoryImplementation(20);
			Controller c = new Controller(r);
			Car c1 = new Car("BMW","I",1200,"red");
			Car c2 = new Car("AUDI","I",912,"green");
			Truck t1 = new Truck("VOLVO","II",2800,2000);
			Truck t2 = new Truck("MAN","III",4000,3000);
			Motorcycle m1 = new Motorcycle("BMW","I",500,"Dirt");
			Motorcycle m2 = new Motorcycle("Kavasaki","I",1500,"Sport");
			r.addVehicle(c1);
			r.addVehicle(c2);
			r.addVehicle(t1);
			r.addVehicle(t2);
			r.addVehicle(m1);
			r.addVehicle(m2);
			//r.addVehicle(c1);
			printRepo(r);
			System.out.println("\n\n");
			printRepo(c.filterByPrice(2000));
			//System.out.println(r.getRepo().length);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}
