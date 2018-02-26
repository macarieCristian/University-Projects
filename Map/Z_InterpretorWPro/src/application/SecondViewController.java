package application;

import java.util.ArrayList;
import java.util.List;

import controller.Controller;
import controller.ControllerException;
import domain.Dictionary;
import domain.ExeStack;
import domain.FileData;
import domain.FileTable;
import domain.GuiPair;
import domain.Heap;
import domain.IDictionary;
import domain.IFileTable;
import domain.IHeap;
import domain.IList;
import domain.IProcTable;
import domain.IStack;
import domain.MyPair;
import domain.OutList;
import domain.PrgState;
import domain.ProcTable;
import javafx.application.Platform;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.MenuItem;
import javafx.scene.control.SelectionMode;
import javafx.scene.control.TableColumn;
import javafx.scene.control.TableView;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.util.Pair;
import repository.IRepository;
import repository.Repository;
import statement.IStatement;
import expression.ArithmeticExpression;
import expression.VarExpression;
import statement.AssignStatement;
import statement.CompStatement;
import statement.PrintStatement;


public class SecondViewController 
{
	
	@FXML
	private MenuItem start;
	
	@FXML
    private TextField numOfPrgStates;

    @FXML
    private TableView<Pair<Integer, Integer>> heapTable;
    @FXML
    private TableColumn<Pair<Integer, Integer>, Integer> heapTableColumnAddress;
    @FXML
    private TableColumn<Pair<Integer, Integer>, Integer> heapTableColumnValue;
    
    @FXML
    private TableView<GuiPair> lockTable;
    @FXML
    private TableColumn<GuiPair, String> locationColumn;
    @FXML
    private TableColumn<GuiPair, IStatement> valueColumn;

    @FXML
    private TableView<Pair<Integer, FileData>> fileTable;
    @FXML
    private TableColumn<Pair<Integer, FileData>, Integer> fileTableColumnId;
    @FXML
    private TableColumn<Pair<Integer, FileData>, FileData> fileTableColumnFileName;

    @FXML
    private TableView<Pair<String, Integer>> symbolTable;
    @FXML
    private TableColumn<Pair<String, Integer>, String> symbolTableColumnVarName;
    @FXML
    private TableColumn<Pair<String, Integer>, Integer> symbolTableColumnValue;

    @FXML
    private ListView<Integer> outList;

    @FXML
    private ListView<PrgState> prgStateIdList;

    @FXML
    private ListView<IStatement> exeStackList;

    @FXML
    private Button runOneStepButton;
    
    
    private IRepository repo;
    private Controller ctrl;
//    private IStatement stm;
//    
//    public SecondViewController(IStatement s)
//    {
//    	stm = s;
//    }
    
    
    @FXML
	public void initialize() 
	{
    	IStack<IStatement> stack = new ExeStack<IStatement>();
    	IStack<IDictionary<String,Integer>> symbolTable = new ExeStack<IDictionary<String,Integer>>();
    	IDictionary<String,Integer> sym1 = new Dictionary<String,Integer>();
    	symbolTable.push(sym1);
		IList<Integer> messages = new OutList<Integer>();
		IFileTable<Integer,FileData> fileTable = new FileTable<Integer,FileData>();
		IHeap<Integer,Integer> heap = new Heap<Integer,Integer>();
		IProcTable<String,MyPair> lock = new ProcTable<String,MyPair>();
		IStatement add = new CompStatement(new AssignStatement("v",new ArithmeticExpression('+',new VarExpression("a"),new VarExpression("b"))),
											new PrintStatement(new VarExpression("v")));
		MyPair mp1 = new MyPair(add);
		mp1.getListOfVars().add("a");
		mp1.getListOfVars().add("b");
		
		IStatement prod = new CompStatement(new AssignStatement("v",new ArithmeticExpression('*',new VarExpression("a"),new VarExpression("b"))),
				new PrintStatement(new VarExpression("v")));
		
		MyPair mp2 = new MyPair(prod);
		mp2.getListOfVars().add("a");
		mp2.getListOfVars().add("b");
		
		lock.add("sum", mp1);
		lock.add("product", mp2);
		
		
		IStatement stm = Transp.stm;
		
		stack.push(stm);
		PrgState prg = new PrgState(stack,symbolTable,messages,fileTable,heap,lock,stm);
		
		repo = new Repository("OutFile.txt");
		repo.addPrgState(prg);
		ctrl = new Controller(repo);
		
		//start pop
		numOfPrgStates.setText(repo.getPrgList().size()+"");
		numOfPrgStates.setEditable(false);
		numOfPrgStates.setMouseTransparent(true);
		numOfPrgStates.setFocusTraversable(false);
		populatePrgStateIdList();
		populateExeStack(prg);
		populateProcTable(prg);
		//
		
		heapTableColumnAddress.setCellValueFactory(new PropertyValueFactory<Pair<Integer, Integer>, Integer>("key"));
		heapTableColumnValue.setCellValueFactory(new PropertyValueFactory<Pair<Integer, Integer>, Integer>("value"));
		fileTableColumnId.setCellValueFactory(new PropertyValueFactory<Pair<Integer, FileData>, Integer>("key"));
		fileTableColumnFileName.setCellValueFactory(new PropertyValueFactory<Pair<Integer, FileData>, FileData>("value"));
		symbolTableColumnVarName.setCellValueFactory(new PropertyValueFactory<Pair<String, Integer>, String>("key"));
		symbolTableColumnValue.setCellValueFactory(new PropertyValueFactory<Pair<String, Integer>, Integer>("value"));
		locationColumn.setCellValueFactory(new PropertyValueFactory<GuiPair, String>("name"));
		valueColumn.setCellValueFactory(new PropertyValueFactory<GuiPair, IStatement>("stm"));
		
		
	}
    
    public void selectionItemChangedHandler()
    {
    	int idx = prgStateIdList.getSelectionModel().getSelectedIndex();
    	if(idx != -1)
    	{
	    	ObservableList<PrgState> stats = prgStateIdList.getItems();
	    	populateSymbolTable(stats.get(idx));
	    	populateExeStack(stats.get(idx));
    	}
    }
    
    private void populateHeapTable(PrgState ps)
    {
        ObservableList<Pair<Integer, Integer>> heapList = FXCollections.observableArrayList();
        IHeap<Integer, Integer> heap = ps.getHeap();
        for (Integer key: heap.getAll())
            heapList.add(new Pair<Integer, Integer>(key, heap.getValue(key)));
        heapTable.setItems(heapList);
    }
    
    private void populateProcTable(PrgState ps)
    {
    	ObservableList<GuiPair> lockList = FXCollections.observableArrayList();
        IProcTable<String, MyPair> lock = ps.getProc();
        for (String key: lock.getAll())
            lockList.add(new GuiPair(key,lock.getValue(key).getListOfVars(),lock.getValue(key).getStm()));
        lockTable.setItems(lockList);
    }
    
    private void populateFileTable(PrgState ps)
    {
    	ObservableList<Pair<Integer,FileData>> fileList = FXCollections.observableArrayList();
    	IFileTable<Integer,FileData> files = ps.getFileTable();
    	for(Integer key : files.getAll())
    	{
    		fileList.add(new Pair<Integer,FileData>(key,files.getValue(key)));
    	}
    	fileTable.setItems(fileList);
    }
    
    private void populateOutList(PrgState ps)
    {
    	ObservableList<Integer> outList = FXCollections.observableArrayList();
    	IList<Integer> out = ps.getOut();
    	for(Integer i : out.getAll())
    	{
    		outList.add(i);
    	}
    	this.outList.setItems(outList);
    }
    
    private void populatePrgStateIdList()
    {
    	ObservableList<PrgState> prgList = FXCollections.observableArrayList();
    	List<PrgState> list = repo.getPrgList();
    	prgList.setAll(list);
    	this.prgStateIdList.setItems(prgList);
    }
    
    private void populateSymbolTable(PrgState ps)
    {
    	ObservableList<Pair<String,Integer>> symbList = FXCollections.observableArrayList();
    	IDictionary<String,Integer> symb = ps.getStackOfSym().first();
    	for(String key : symb.getAll())
    	{
    		symbList.add(new Pair<String,Integer>(key,symb.getValue(key)));
    	}
    	this.symbolTable.setItems(symbList);
    }

    private void populateExeStack(PrgState ps)
    {
    	ObservableList<IStatement> exeStackList = FXCollections.observableArrayList();
    	IStack<IStatement> stack = ps.getExeStack();
    	for(IStatement st : stack.getAll())
    	{
    		exeStackList.add(st);
    	}
    	this.exeStackList.setItems(exeStackList);
    }
    
    
    public void runOneStepButtonHandler()
    {
    	try
    	{
	    	List<PrgState> repoList = repo.getPrgList();
	    	if(repoList.size()==0)
	    	{
	    		System.out.println("The end.");
	    		end();
	    		return;
	    	}
	    	
	    	ctrl.oneStepForAllPrg(repoList);
	        PrgState program = null;
	        try {
	            program = repoList.get(0);
	        }
	        catch(Exception er){}
	
	        repo.setPrgList(ctrl.removeCompletedPrg(repoList));
	    	
	    	populateHeapTable(program);
	    	populateProcTable(program);
	    	populateFileTable(program);
	    	populateOutList(program);
	    	populatePrgStateIdList();
	    	
	    	
	    	int idx = prgStateIdList.getSelectionModel().getSelectedIndex();
	    	ObservableList<PrgState> stats = prgStateIdList.getItems();
	    	
	    	if(idx == -1)
	    	{
	    		populateSymbolTable(program);
	        	populateExeStack(program);
	        	
	    	}
	    	else
	    	{
	    		populateSymbolTable(stats.get(idx));
	        	populateExeStack(stats.get(idx));
	    	}
	    	
	    	numOfPrgStates.setText(repo.getPrgList().size()+"");
	    	
	    	if(repo.getPrgList().size() == 0)
	    	{
	    		ctrl.getExecutor().shutdown();
	    	}
    	}
    	catch(ControllerException e)
    	{
    		Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Error!");
            alert.setHeaderText("InterpretorError");
            alert.setContentText(e.getMessage());
            alert.showAndWait();
            ctrl.getExecutor().shutdown();
            
            Stage st = (Stage)runOneStepButton.getScene().getWindow();
            st.close();

            
    	}
    	
    }
    
    
    private void end()
    {
    	Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle("Error!");
        alert.setHeaderText("InterpretorError");
        alert.setContentText("You've reached the end!");
        alert.showAndWait();
    }
    
    
    
    
    
    
    
    
    
    
    
}
