package view;

import controller.Controller;
import controller.ControllerException;

public class RunExample extends Command 
{

	private Controller ctrl;
	
	public RunExample(String k, String desc, Controller control) 
	{
		super(k, desc);
		ctrl = control;
	}

	@Override
	public void execute() 
	{
		try
		{
			ctrl.allStep();
		}
		catch(ControllerException ce)
		{
			System.out.println(ce);
		}
		
	}

}
