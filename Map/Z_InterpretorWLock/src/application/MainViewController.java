package application;

import java.io.IOException;

import controller.Controller;
import domain.Dictionary;
import domain.ExeStack;
import domain.FileData;
import domain.FileTable;
import domain.Heap;
import domain.IDictionary;
import domain.IFileTable;
import domain.IHeap;
import domain.IList;
import domain.IStack;
import domain.OutList;
import domain.PrgState;
import expression.ArithmeticExpression;
import expression.BooleanExpression;
import expression.ConstExpression;
import expression.ReadH;
import expression.VarExpression;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import repository.IRepository;
import repository.Repository;
import statement.AssignStatement;
import statement.CloseRFile;
import statement.CompStatement;
import statement.ForStatement;
import statement.ForkStatement;
import statement.IStatement;
import statement.IfStatement;
import statement.Lock;
import statement.NewH;
import statement.NewLock;
import statement.OpenRFile;
import statement.PrintStatement;
import statement.ReadFile;
import statement.RepeatStatement;
import statement.Sleep;
import statement.SquenceStatement;
import statement.Unlock;
import statement.WhileStatement;
import statement.WriteH;

public class MainViewController 
{
	
	@FXML
	private ListView<IStatement> listView;
	
	@FXML
	private MenuItem runItem;
	
	
	@FXML
	public void initialize() 
	{
			listView.setItems(getList());
			listView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
			listView.getSelectionModel().clearAndSelect(0);
	}
	
	private ObservableList<IStatement> getList()
	{
		IStatement stm12 = new CompStatement(new ForkStatement(new CompStatement(new AssignStatement("i",new ConstExpression(10)),new WhileStatement(new BooleanExpression(">",new VarExpression("i"),new ConstExpression(5)),new CompStatement(new PrintStatement(new VarExpression("i")),new AssignStatement("i",new ArithmeticExpression('-',new VarExpression("i"),new ConstExpression(1))))))),
				new ForkStatement(new CompStatement(new AssignStatement("i",new ConstExpression(1)),new WhileStatement(new BooleanExpression("<=",new VarExpression("i"),new ConstExpression(5)),new CompStatement(new PrintStatement(new VarExpression("i")),new AssignStatement("i",new ArithmeticExpression('+',new VarExpression("i"),new ConstExpression(1))))))));
		IStatement stm = new CompStatement(new AssignStatement("v",new ConstExpression(2)),new PrintStatement(new VarExpression("v")));
		IStatement stm1 = new IfStatement(new ConstExpression(1),new PrintStatement(new ConstExpression(4)),new PrintStatement(new ConstExpression(5)));
		
		IStatement asgnVar = new AssignStatement("x",new ArithmeticExpression('-',new ConstExpression(50),new ConstExpression(49)));
		IStatement ifstm = new IfStatement(new VarExpression("x"),new AssignStatement("x",new ConstExpression(13)),new AssignStatement("x",new ConstExpression(10)));
		IStatement stm2 = new CompStatement(asgnVar,new CompStatement(ifstm,new PrintStatement(new VarExpression("x"))));
		
		IStatement stm3 = new CompStatement(new OpenRFile("file","ex1.txt"),new CompStatement(new ReadFile(new VarExpression("file"),"x"),new CloseRFile(new VarExpression("file"))));
		IStatement stm4 = new CompStatement(new OpenRFile("file","ex1.txt"),new CompStatement(new ReadFile(new VarExpression("file"),"x"),new CompStatement(new ReadFile(new VarExpression("file"),"y"),new CloseRFile(new VarExpression("file")))));
		IStatement stm5 = new CompStatement(new AssignStatement("a",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(20)),new CompStatement(new NewH("b",new ConstExpression(40)),new PrintStatement(new VarExpression("a")))));
		IStatement stm6 = new CompStatement(new AssignStatement("a",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(20)),new CompStatement(new NewH("b",new ConstExpression(40)),new CompStatement(new PrintStatement(new ArithmeticExpression('+',new ConstExpression(100),new ReadH("a"))),new PrintStatement(new ArithmeticExpression('+',new ConstExpression(100),new ReadH("b")))))));
		
		IStatement stm7 = new CompStatement(new AssignStatement("a",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(20)),new CompStatement(new NewH("b",new ConstExpression(40)),new CompStatement(new NewH("a",new ConstExpression(-10)),new CompStatement(new PrintStatement(new ArithmeticExpression('+',new ConstExpression(100),new ReadH("b"))),new WriteH("b",new ConstExpression(99)))))));
		
		IStatement stm8 = new CompStatement(new AssignStatement("v",new ConstExpression(10)),new CompStatement(new NewH("v",new ConstExpression(20)),new CompStatement(new NewH("a",new ConstExpression(22)),new CompStatement(new WriteH("a",new ConstExpression(30)),new CompStatement(new PrintStatement(new VarExpression("a")),new CompStatement(new PrintStatement(new ReadH("a")),new AssignStatement("a",new ConstExpression(0))))))));
		IStatement stmex = new CompStatement(new AssignStatement("x",new BooleanExpression("==",new BooleanExpression("<",new ConstExpression(5),new ConstExpression(10)),new ConstExpression(5))),new PrintStatement(new VarExpression("x")));
		
		IStatement stm9 = new CompStatement(new AssignStatement("i",new ConstExpression(0)),new WhileStatement(new BooleanExpression("<",new VarExpression("i"),new ConstExpression(5)),new CompStatement(new PrintStatement(new VarExpression("i")),new AssignStatement("i",new ArithmeticExpression('+',new VarExpression("i"),new ConstExpression(1))))));
		
		IStatement stm10 = new CompStatement(new OpenRFile("f1","ex1.txt"),new ReadFile(new VarExpression("f1"),"var"));
		
		IStatement stm11 = new CompStatement(new AssignStatement("v",new ConstExpression(10)),new CompStatement(new NewH("a",new ConstExpression(22)),
				new CompStatement(new ForkStatement(new CompStatement(new WriteH("a",new ConstExpression(30)),
						new CompStatement(new AssignStatement("v",new ConstExpression(32)),new CompStatement(
								new PrintStatement(new VarExpression("v")),new PrintStatement(new ReadH("a")))))),
						new CompStatement(new PrintStatement(new VarExpression("v")),new PrintStatement(new ReadH("a"))))));
		
		IStatement stm13 = new CompStatement(new AssignStatement("i",new ConstExpression(1)),new WhileStatement(new BooleanExpression("<",new VarExpression("i"),
				new ConstExpression(10)), new CompStatement(new ForkStatement(stm12), new AssignStatement("i",new ArithmeticExpression('+',new VarExpression("i"),
						new ConstExpression(1))))));
		
		IStatement stm14 = new CompStatement(new AssignStatement("v",new ConstExpression(20)),
				new CompStatement(new ForStatement(new AssignStatement("v",new ConstExpression(0)),
						new BooleanExpression("<",new VarExpression("v"),new ConstExpression(3)),
						new AssignStatement("v",new ArithmeticExpression('+',new VarExpression("v"),
								new ConstExpression(1))),
						new ForkStatement(new CompStatement(new PrintStatement(new VarExpression("v")),
								new AssignStatement("v",new ArithmeticExpression('+',new VarExpression("v"),
								new ConstExpression(1)))))),new PrintStatement(new ArithmeticExpression('*',new VarExpression("v"),new ConstExpression(10)))));
		
		IStatement f1 = new ForkStatement(new CompStatement(new Lock("x"),
				new CompStatement(new WriteH("v1",new ArithmeticExpression('-',new ReadH("v1"),new ConstExpression(1))),
				new Unlock("x"))));

		IStatement f2 = new CompStatement(new Lock("x"),
				new CompStatement(new WriteH("v1",new ArithmeticExpression('+',new ReadH("v1"),new ConstExpression(1))),
				new Unlock("x")));

		IStatement f3 = new ForkStatement(new CompStatement(new Lock("q"),
				new CompStatement(new WriteH("v2",new ArithmeticExpression('+',new ReadH("v2"),new ConstExpression(5))),
				new Unlock("q"))));

		IStatement f4 = new CompStatement(new AssignStatement("m",new ConstExpression(100)),
				new CompStatement(new Lock("q"),
				new CompStatement(new WriteH("v2",new ArithmeticExpression('+',new ReadH("v2"),new ConstExpression(1))),new Unlock("q"))));

		IStatement stm15 = new CompStatement(new NewH("v1",new ConstExpression(20)),
				   new CompStatement(new NewH("v2",new ConstExpression(30)),
				   new CompStatement(new NewLock("x"),
				   new CompStatement(new ForkStatement(new CompStatement(f1,f2)),
				   new CompStatement(new NewLock("q"),
				   new CompStatement(new ForkStatement(new CompStatement(f3,f4)),
				   new CompStatement(new AssignStatement("z",new ConstExpression(200)),
				   new CompStatement(new AssignStatement("z",new ConstExpression(300)),
				   new CompStatement(new AssignStatement("z",new ConstExpression(400)),
				   new CompStatement(new Lock("x"),
				   new CompStatement(new PrintStatement(new ReadH("v1")),
				   new CompStatement(new Unlock("x"),
				   new CompStatement(new Lock("q"),
				   new CompStatement(new PrintStatement(new ReadH("v2")),new Unlock("q")))))))))))))));

		IStatement stm16 = new SquenceStatement
		(
				new AssignStatement("x",new ConstExpression(1)),
				new PrintStatement(new VarExpression("x")),
				new WhileStatement(new BooleanExpression("<",new VarExpression("x"),new ConstExpression(10)),
										new SquenceStatement
										(
												new PrintStatement(new VarExpression("x")),
												new AssignStatement("x",new ArithmeticExpression('+',new VarExpression("x"),new ConstExpression(1)))
										)
								  ),
				new AssignStatement("x",new ConstExpression(5)),
				new PrintStatement(new VarExpression("x"))
		);
		
		IStatement stm17 = new SquenceStatement
		(
				new NewH("v1",new ConstExpression(20)),
				new NewH("v2",new ConstExpression(30)),
				new NewLock("x"),
				new ForkStatement
				(	
					new SquenceStatement
					(
						new ForkStatement
						(
							new SquenceStatement
							(
								new Lock("x"),
								new WriteH("v1",new ArithmeticExpression('-',new ReadH("v1"),new ConstExpression(1))),
								new Unlock("x")
							)
						),
						new Lock("x"),
						new WriteH("v1",new ArithmeticExpression('+',new ReadH("v1"),new ConstExpression(1))),
						new Unlock("x")
					)
				),
				new NewLock("q"),
				new ForkStatement
				(	
					new SquenceStatement
					(
						new ForkStatement
						(
							new SquenceStatement
							(
								new Lock("q"),
								new WriteH("v2",new ArithmeticExpression('+',new ReadH("v2"),new ConstExpression(5))),
								new Unlock("q")
							)
						),
						new AssignStatement("m",new ConstExpression(100)),
						new Lock("q"),
						new WriteH("v2",new ArithmeticExpression('+',new ReadH("v2"),new ConstExpression(1))),
						new Unlock("q")
					)
				),
				new AssignStatement("z",new ConstExpression(200)),
				new AssignStatement("z",new ConstExpression(300)),
				new AssignStatement("z",new ConstExpression(400)),
				new Lock("x"),
				new PrintStatement(new ReadH("v1")),
				new Unlock("x"),
				new Lock("q"),
				new PrintStatement(new ReadH("v2")),
				new Unlock("q")
		);
		
		IStatement stm18 = new SquenceStatement
		(
				new AssignStatement("v",new ConstExpression(0)),
				new WhileStatement(new BooleanExpression("<",new VarExpression("v"),new ConstExpression(3)),
						new SquenceStatement
						(
								new ForkStatement
								(
										new SquenceStatement
										(
												new PrintStatement(new VarExpression("v")),
												new AssignStatement("v",new ArithmeticExpression('+',new VarExpression("v"),new ConstExpression(1)))
										)
										
								),
								new AssignStatement("v",new ArithmeticExpression('+',new VarExpression("v"),new ConstExpression(1)))
						)
						
				),
				new Sleep(new ConstExpression(15)),
				new PrintStatement(new ArithmeticExpression('*',new VarExpression("v"),new ConstExpression(10)))
		);

		IStatement stm19 = new SquenceStatement
				(
					new AssignStatement("v",new ConstExpression(0)),
					new RepeatStatement(new SquenceStatement
							(
									new PrintStatement(new VarExpression("v")),
									new AssignStatement("v",new ArithmeticExpression('+',new VarExpression("v"),new ConstExpression(1)))
							),
							new BooleanExpression("==",new VarExpression("v"),new ConstExpression(10)))
				);
		
		IStatement stm20 = new SquenceStatement
		(
				new AssignStatement("v",new ConstExpression(0)),
				new RepeatStatement(new SquenceStatement
						(
								new ForkStatement
								(
										new SquenceStatement
										(
												new PrintStatement(new VarExpression("v")),
												new AssignStatement("v",new ArithmeticExpression('-',new VarExpression("v"),new ConstExpression(1)))
										)
								),
								new AssignStatement("v",new ArithmeticExpression('+',new VarExpression("v"),new ConstExpression(1)))
						),
						new BooleanExpression("==",new VarExpression("v"),new ConstExpression(3))),
				new AssignStatement("x",new ConstExpression(1)),
				new AssignStatement("y",new ConstExpression(2)),
				new AssignStatement("z",new ConstExpression(3)),
				new AssignStatement("w",new ConstExpression(4)),
				new PrintStatement(new ArithmeticExpression('*',new VarExpression("v"),new ConstExpression(10)))
				
		);
		
		ObservableList<IStatement> list = FXCollections.observableArrayList();
		list.addAll(stm,stm1,stm2,stm3,stm4,stm5,stm6,stm7,stm8,stmex,stm9,stm10,stm11,stm12,stm13,stm14,stm15,stm16,stm17,stm18,stm19,stm20);
		return list;
	}

	public void runItemHandler()
	{
		int idx = listView.getSelectionModel().getSelectedIndex();
		ObservableList<IStatement> list = listView.getItems();
		IStatement st = list.get(idx);
		Transp.stm = st;
		
		Stage primaryStage = new Stage();
		try 
		{
			FXMLLoader loader = new FXMLLoader(getClass().getResource("SecondWindow.fxml"));
			//loader.setController(new SecondViewController(st));
			VBox root = (VBox)loader.load();
			
			Scene scene = new Scene(root);
			scene.getStylesheets().add(getClass().getResource("SecondWindow.css").toExternalForm());
			
			primaryStage.setScene(scene);
			primaryStage.setTitle("Execution Window for program: "+idx);
			primaryStage.show();
			
		} 
		catch(Exception e) 
		{
			e.printStackTrace();
		}
	}

}
