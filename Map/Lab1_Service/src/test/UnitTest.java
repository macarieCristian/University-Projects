package test;
import org.junit.Assert.*;
import org.junit.Test;

import controller.Controller;
import domain.Car;
import domain.Motorcycle;
import domain.Truck;
import repository.Repository;
import repository.RepositoryMemoryImplementation;


public class UnitTest {
	
	Repository rr;

	public void setUp() throws Exception
	{
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
		
		rr=r;
	}
	
	@Test
	public void testRepo() throws Exception
	{
		try
		{
		this.setUp();
		assert(rr.getSize()==6);
		Car c1 = new Car("BMW","I",1200,"red1");
		rr.addVehicle(c1);
		assert(rr.getSize()==7);
		Car c2 = new Car("BMW","I",1200,"red1");
		}
		catch (Exception e) 
		{
			e.printStackTrace();
			System.out.println("Test error.");
		}
	}
	
}
