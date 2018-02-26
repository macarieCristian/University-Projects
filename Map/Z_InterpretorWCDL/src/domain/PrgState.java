package domain;

import statement.IStatement;

public class PrgState 
{
	private IStack<IStatement> exeStack;
	private IDictionary<String,Integer> symbolTable;
	private IList<Integer> out;
	private IFileTable<Integer,FileData> fileTable;
	private IHeap<Integer,Integer> heap;
	private ILatchTable<Integer,Integer> latch;
	private IStatement originalProg;
	private int id;
	
	public boolean isNotCompleted()
	{
		return !exeStack.isEmpty();
	}
	
	public PrgState oneStep() 
	{
		if(exeStack.isEmpty())
			throw new DomainException("Stack is empty!");
		IStatement crtStmt = exeStack.pop();
		return crtStmt.execute(this);
	}
	
	public PrgState(IStack<IStatement> exeS, IDictionary<String,Integer> symbolT, IList<Integer> ot, IFileTable<Integer,FileData> ft, IHeap<Integer,Integer> hep, ILatchTable<Integer,Integer> latchs, IStatement prog)
	{
		exeStack = exeS;
		symbolTable = symbolT;
		out = ot;
		fileTable = ft;
		heap = hep;
		latch = latchs;
		originalProg = prog;
		id = ThreadIDGenerator.generateID();
	}
	
	public IHeap<Integer, Integer> getHeap() {return heap;}

	public void setHeap(IHeap<Integer, Integer> heap) {this.heap = heap;}

	public IFileTable<Integer, FileData> getFileTable() {return fileTable;}

	public void setFileTable(IFileTable<Integer, FileData> fileTable) {this.fileTable = fileTable;}

	public IStack<IStatement> getExeStack() {return exeStack;}

	public IDictionary<String, Integer> getSymbolTable() {return symbolTable;}

	public IList<Integer> getOut() {return out;}

	public IStatement getOriginalProg() {return originalProg;}
	
	@Override
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		sb.append("\nid: "+id+"\n   Execution stack:  "+exeStack+"\n");
		sb.append("   Symbol Table:  "+symbolTable+"\n");
		sb.append("   Output List:   "+out+"\n");
		sb.append("   FileTable:   "+fileTable+"\n");
		sb.append("   Heap:   "+heap+"\n");
		sb.append("   LatchTable:   "+latch+"\n");
		sb.append("   Original program:   "+originalProg+"\n");
		return sb.toString();
	}


	public ILatchTable<Integer, Integer> getLatch() {
		return latch;
	}

	public void setLatch(ILatchTable<Integer, Integer> latch) {
		this.latch = latch;
	}

	public int getId() {return id;}
	
//	public void setId(int d) {id = d;}

	public void setExeStack(IStack<IStatement> exeStack) {this.exeStack = exeStack;}

	public void setSymbolTable(IDictionary<String, Integer> symbolTable) {this.symbolTable = symbolTable;}

	public void setOut(IList<Integer> out) {this.out = out;}

	public void setOriginalProg(IStatement originalProg) {this.originalProg = originalProg;}

	
}
