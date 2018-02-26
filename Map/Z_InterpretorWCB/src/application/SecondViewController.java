package application;

import java.util.List;

import controller.Controller;
import controller.ControllerException;
import domain.BarrierTable;
import domain.Dictionary;
import domain.ExeStack;
import domain.FileData;
import domain.FileTable;
import domain.GuiPair;
import domain.Heap;
import domain.IBarrierTable;
import domain.IDictionary;
import domain.IFileTable;
import domain.IHeap;
import domain.IList;
import domain.IStack;
import domain.MyPair;
import domain.OutList;
import domain.PrgState;
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
    private TableView<GuiPair> barrierTable;
    @FXML
    private TableColumn<GuiPair, Integer> locationColumn;
    @FXML
    private TableColumn<GuiPair, String> listColumn;
    @FXML
    private TableColumn<GuiPair, Integer> valueColumn;

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
		IDictionary<String,Integer> symbolTable = new Dictionary<String,Integer>();
		IList<Integer> messages = new OutList<Integer>();
		IFileTable<Integer,FileData> fileTable = new FileTable<Integer,FileData>();
		IHeap<Integer,Integer> heap = new Heap<Integer,Integer>();
		IBarrierTable<Integer,MyPair> lock = new BarrierTable<Integer,MyPair>();
		
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
		//
		
		heapTableColumnAddress.setCellValueFactory(new PropertyValueFactory<Pair<Integer, Integer>, Integer>("key"));
		heapTableColumnValue.setCellValueFactory(new PropertyValueFactory<Pair<Integer, Integer>, Integer>("value"));
		fileTableColumnId.setCellValueFactory(new PropertyValueFactory<Pair<Integer, FileData>, Integer>("key"));
		fileTableColumnFileName.setCellValueFactory(new PropertyValueFactory<Pair<Integer, FileData>, FileData>("value"));
		symbolTableColumnVarName.setCellValueFactory(new PropertyValueFactory<Pair<String, Integer>, String>("key"));
		symbolTableColumnValue.setCellValueFactory(new PropertyValueFactory<Pair<String, Integer>, Integer>("value"));
		locationColumn.setCellValueFactory(new PropertyValueFactory<GuiPair, Integer>("key"));
		listColumn.setCellValueFactory(new PropertyValueFactory<GuiPair, String>("list"));
		valueColumn.setCellValueFactory(new PropertyValueFactory<GuiPair, Integer>("num"));
		
		
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
    
    private void populateBarrierTable(PrgState ps)
    {
        ObservableList<GuiPair> heapList = FXCollections.observableArrayList();
        IBarrierTable<Integer, MyPair> bar = ps.getCyclicBarrier();
        for (Integer key: bar.getAll())
            heapList.add(new GuiPair(key,bar.getValue(key).getList(),bar.getValue(key).getNum()));
        barrierTable.setItems(heapList);
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
    	IDictionary<String,Integer> symb = ps.getSymbolTable();
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
	    	populateBarrierTable(program);
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