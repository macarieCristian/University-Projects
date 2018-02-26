package domain;


import statement.IStatement;

public class PrgState 
{
	private IStack<IStatement> exeStack;
	private IStack<IDictionary<String,Integer>> stackOfSym;
	//private IDictionary<String,Integer> symbolTable;
	private IList<Integer> out;
	private IFileTable<Integer,FileData> fileTable;
	private IHeap<Integer,Integer> heap;
	private IProcTable<String,MyPair> proc;
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
	
	public PrgState(IStack<IStatement> exeS, IStack<IDictionary<String,Integer>> stackOfSyms, IList<Integer> ot, IFileTable<Integer,FileData> ft, IHeap<Integer,Integer> hep, IProcTable<String, MyPair> locks, IStatement prog)
	{
		exeStack = exeS;
		stackOfSym = stackOfSyms;
		out = ot;
		fileTable = ft;
		heap = hep;
		proc = locks;
		originalProg = prog;
		id = ThreadIDGenerator.generateID();
	}
	
	public IHeap<Integer, Integer> getHeap() {return heap;}

	public void setHeap(IHeap<Integer, Integer> heap) {this.heap = heap;}

	public IFileTable<Integer, FileData> getFileTable() {return fileTable;}

	public void setFileTable(IFileTable<Integer, FileData> fileTable) {this.fileTable = fileTable;}

	public IStack<IStatement> getExeStack() {return exeStack;}

	

	public IStack<IDictionary<String, Integer>> getStackOfSym() {
		return stackOfSym;
	}

	public void setStackOfSym(IStack<IDictionary<String, Integer>> stackOfSym) {
		this.stackOfSym = stackOfSym;
	}

	public IList<Integer> getOut() {return out;}

	public IStatement getOriginalProg() {return originalProg;}
	
	@Override
	public String toString()
	{
		StringBuffer sb = new StringBuffer();
		sb.append("\nid: "+id+"\n   Execution stack:  "+exeStack+"\n");
		sb.append("   Stack Of Sym:  "+stackOfSym+"\n");
		sb.append("   Output List:   "+out+"\n");
		sb.append("   FileTable:   "+fileTable+"\n");
		sb.append("   Heap:   "+heap+"\n");
		sb.append("   ProcTable:   "+proc+"\n");
		sb.append("   Original program:   "+originalProg+"\n");
		return sb.toString();
	}

	

	

	public IProcTable<String, MyPair> getProc() {
		return proc;
	}

	public void setProc(IProcTable<String, MyPair> proc) {
		this.proc = proc;
	}

	public int getId() {return id;}
	
//	public void setId(int d) {id = d;}

	public void setExeStack(IStack<IStatement> exeStack) {this.exeStack = exeStack;}

	

	public void setOut(IList<Integer> out) {this.out = out;}

	public void setOriginalProg(IStatement originalProg) {this.originalProg = originalProg;}

	
}
