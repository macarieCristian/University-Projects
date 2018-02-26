package main;

import java.util.Scanner;

import controller.Controller;
import controller.ControllerException;
import domain.DomainException;
import domain.FileData;
import domain.Dictionary;
import domain.FileTable;
import domain.Heap;
import domain.IDictionary;
import domain.IFileTable;
import domain.IHeap;
import domain.ILatchTable;
import domain.IList;
import domain.IStack;
import domain.LatchTable;
import domain.OutList;
import domain.ExeStack;
import domain.PrgState;
import expression.ArithmeticExpression;
import expression.BooleanExpression;
import expression.ConstExpression;
import expression.ReadH;
import expression.VarExpression;
import repository.IRepository;
import repository.Repository;
import repository.RepositoryException;
import statement.AssignStatement;
import statement.CloseRFile;
import statement.CompStatement;
import statement.ForkStatement;
import statement.IStatement;
import statement.IfStatement;
import statement.NewH;
import statement.OpenRFile;
import statement.PrintStatement;
import statement.ReadFile;
import statement.WhileStatement;
import statement.WriteH;
import view.Command;
import view.ExitCommand;
import view.RunExample;
import view.TextMenu;

public class Interpretor {

	public static void main(String[] args) 
	{
		
			IStack<IStatement> stack = new ExeStack<IStatement>();
			IDictionary<String,Integer> symbolTable = new Dictionary<String,Integer>();
			IList<Integer> messages = new OutList<Integer>();
			IFileTable<Integer,FileData> fileTable = new FileTable<Integer,FileData>();
			IHeap<Integer,Integer> heap = new Heap<Integer,Integer>();
			ILatchTable<Integer,Integer> lock = new LatchTable<Integer,Integer>();
			
			IStatement stm = new CompStatement(new AssignStatement("v",new ConstExpression(2)),new PrintStatement(new VarExpression("v")));
			//IStatement stm1 = new IfStatement(new ConstExpression(1),new PrintStatement(new ConstExpression(4)),new PrintStatement(new ConstExpression(5)));
			
//			IStatement asgnVar = new AssignStatement("x",new ArithmeticExpression('-',new ConstExpression(50),new ConstExpression(49)));
//			IStatement ifstm = new IfStatement(new VarExpression("x"),new AssignStatement("x",new ConstExpression(13)),new AssignStatement("x",new ConstExpression(10)));
//			IStatement stm2 = new CompStatement(asgnVar,new CompStatement(ifstm,new PrintStatement(new VarExpression("x"))));
			
//			IStatement stm3 = new CompStatement(new OpenRFile("file","ex1.txt"),new CompStatement(new ReadFile(new VarExpression("file"),"x"),new CloseRFile(new VarExpression("file"))));
//			IStatement stm4 = new CompStatement(new OpenRFile("file","ex1.txt"),new CompStatement(new ReadFile(new VarExpression("file"),"x"),new CompStatement(new ReadFile(new VarExpression("file"),"y"),new CloseRFile(new VarExpression("file")))));
//			IStatement stm5 = new CompStatement(new AssignStatement("a",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(20)),new CompStatement(new NewH("b",new ConstExpression(40)),new PrintStatement(new VarExpression("a")))));
//			IStatement stm6 = new CompStatement(new AssignStatement("a",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(20)),new CompStatement(new NewH("b",new ConstExpression(40)),new CompStatement(new PrintStatement(new ArithmeticExpression('+',new ConstExpression(100),new ReadH("a"))),new PrintStatement(new ArithmeticExpression('+',new ConstExpression(100),new ReadH("b")))))));
			
//			IStatement stm7 = new CompStatement(new AssignStatement("a",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(20)),new CompStatement(new NewH("b",new ConstExpression(40)),new CompStatement(new NewH("a",new ConstExpression(-10)),new CompStatement(new PrintStatement(new ArithmeticExpression('+',new ConstExpression(100),new ReadH("b"))),new WriteH("b",new ConstExpression(99)))))));
			
//			v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a));a=0
//			IStatement stm8 = new CompStatement(new AssignStatement("v",new ConstExpression(10)),new CompStatement(new NewH("v",new ConstExpression(20)),new CompStatement(new NewH("a",new ConstExpression(22)),new CompStatement(new WriteH("a",new ConstExpression(30)),new CompStatement(new PrintStatement(new VarExpression("a")),new CompStatement(new PrintStatement(new ReadH("a")),new AssignStatement("a",new ConstExpression(0))))))));
//			IStatement stmex = new CompStatement(new AssignStatement("x",new BooleanExpression("==",new BooleanExpression("<",new ConstExpression(5),new ConstExpression(10)),new ConstExpression(5))),new PrintStatement(new VarExpression("x")));
			
//			IStatement stm9 = new CompStatement(new AssignStatement("i",new ConstExpression(0)),new WhileStatement(new BooleanExpression("<",new VarExpression("i"),new ConstExpression(5)),new CompStatement(new PrintStatement(new VarExpression("i")),new AssignStatement("i",new ArithmeticExpression('+',new VarExpression("i"),new ConstExpression(1))))));
			
//			IStatement stm10 = new CompStatement(new OpenRFile("f1","ex1.txt"),new ReadFile(new VarExpression("f1"),"var"));
			
//			v=10;new(a,22);
//			 fork(wH(a,30);v=32;print(v);print(rH(a)));
//			 print(v);print(rH(a)) 
			
			IStatement stm11 = new CompStatement(new AssignStatement("v",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(22)),
					new CompStatement(new ForkStatement(new CompStatement(new WriteH("a",new ConstExpression(30)),
							new CompStatement(new AssignStatement("v",new ConstExpression(32)),new CompStatement(
									new PrintStatement(new VarExpression("v")),new PrintStatement(new ReadH("a")))))),
							new CompStatement(new PrintStatement(new VarExpression("v")),new PrintStatement(new ReadH("a"))))));
			
			IStatement stm12 = new CompStatement(new ForkStatement(new CompStatement(new AssignStatement("i",new ConstExpression(10)),new WhileStatement(new BooleanExpression(">",new VarExpression("i"),new ConstExpression(5)),new CompStatement(new PrintStatement(new VarExpression("i")),new AssignStatement("i",new ArithmeticExpression('-',new VarExpression("i"),new ConstExpression(1))))))),
					new ForkStatement(new CompStatement(new AssignStatement("i",new ConstExpression(1)),new WhileStatement(new BooleanExpression("<=",new VarExpression("i"),new ConstExpression(5)),new CompStatement(new PrintStatement(new VarExpression("i")),new AssignStatement("i",new ArithmeticExpression('+',new VarExpression("i"),new ConstExpression(1))))))));
			
//			IStatement f1 = new ForkStatement(new CompStatement(new Lock("x"),
//							new CompStatement(new WriteH("v1",new ArithmeticExpression('-',new ReadH("v1"),new ConstExpression(1))),
//							new Unlock("x"))));
//			
//			IStatement f2 = new CompStatement(new Lock("x"),
//							new CompStatement(new WriteH("v1",new ArithmeticExpression('+',new ReadH("v1"),new ConstExpression(1))),
//							new Unlock("x")));
//			
//			IStatement f3 = new ForkStatement(new CompStatement(new Lock("q"),
//							new CompStatement(new WriteH("v2",new ArithmeticExpression('+',new ReadH("v2"),new ConstExpression(5))),
//							new Unlock("q"))));
//			
//			IStatement f4 = new CompStatement(new AssignStatement("m",new ConstExpression(100)),
//							new CompStatement(new Lock("q"),
//							new CompStatement(new WriteH("v2",new ArithmeticExpression('+',new ReadH("v2"),new ConstExpression(1))),new Unlock("q"))));
//			
//			IStatement stm15 = new CompStatement(new NewH("v1",new ConstExpression(20)),
//							   new CompStatement(new NewH("v2",new ConstExpression(30)),
//							   new CompStatement(new NewLock("x"),
//							   new CompStatement(new ForkStatement(new CompStatement(f1,f2)),
//							   new CompStatement(new NewLock("q"),
//							   new CompStatement(new ForkStatement(new CompStatement(f3,f4)),
//							   new CompStatement(new AssignStatement("z",new ConstExpression(200)),
//							   new CompStatement(new AssignStatement("z",new ConstExpression(300)),
//							   new CompStatement(new AssignStatement("z",new ConstExpression(400)),
//							   new CompStatement(new Lock("x"),
//							   new CompStatement(new PrintStatement(new ReadH("v1")),
//							   new CompStatement(new Unlock("x"),
//							   new CompStatement(new Lock("q"),
//							   new CompStatement(new PrintStatement(new ReadH("v2")),new Unlock("q")))))))))))))));
																	
			
			stack.push(stm12);
			PrgState prg = new PrgState(stack,symbolTable,messages,fileTable,heap,lock,stm12);
			
			
//			System.out.print("Enter the textfile name: ");
//			String fileName = sc.nextLine();
			
			IRepository repo = new Repository("OutFile.txt");
			repo.addPrgState(prg);
			Controller ctrl = new Controller(repo);
			
			TextMenu menu = new TextMenu();
			menu.addCommand(new ExitCommand("0","exit."));
			menu.addCommand(new RunExample("1","Run Program.",ctrl));
			
			menu.show();
			//ctrl.allStep();
		
	}

}
