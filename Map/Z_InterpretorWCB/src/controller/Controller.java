package controller;


import java.io.IOException;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.concurrent.Callable;
import java.util.concurrent.ConcurrentHashMap;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.stream.Collectors;
import domain.DomainException;
import domain.FileData;
import domain.IFileTable;
import domain.PrgState;
import repository.IRepository;
import repository.RepositoryException;


public class Controller
{
	
	private IRepository repo;
	private ExecutorService executor;
	
	public Controller(IRepository repo2)
	{
		repo = repo2;
		executor = Executors.newFixedThreadPool(2);
	}
	
	public ExecutorService getExecutor() {return executor;}
	
	public List<PrgState> removeCompletedPrg(List<PrgState> inPrgList)
	{
		return inPrgList.stream().
				filter(ps->ps.isNotCompleted()).
				collect(Collectors.toList());
	}
	
	private Map<Integer,Integer> GarbageCollector(Collection<Integer> symTabValues, Map<Integer,Integer> heap)
	{	
		return heap.entrySet().stream().
				filter(el->symTabValues.contains(el.getKey())).
				collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));
	}
	
	private Map<Integer,FileData> FileManager(IFileTable<Integer,FileData> fileTable)
	{
		fileTable.getContent().entrySet().stream().
		map(x->
		{
			try 
			{
			x.getValue().getFileDescriptor().close();
			return x;
			} 
			catch (IOException e) 
			{
				throw new ControllerException(e.getMessage());
			}
		}).
		collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));
		return new ConcurrentHashMap<Integer,FileData>();
	}
	
	public void oneStepForAllPrg(List<PrgState> prgList)
	{
		try
		{
		//prgList.forEach(prg->repo.logPrgStateExec(prg));
		
		List<Callable<PrgState>> callList = prgList.stream()
				.map((PrgState p)->(Callable<PrgState>)(()->{return p.oneStep();}))
				.collect(Collectors.toList());
		
		
			List<PrgState> newPrgList = executor.invokeAll(callList).stream()
					.map(future->
					{
						try
						{
							return future.get();
						}
						catch(DomainException de)
						{
							throw new ControllerException(de.getMessage());
						}
						catch(RepositoryException re)
						{
							throw new ControllerException(re.getMessage());
						} 
						catch (InterruptedException e) 
						{
							throw new ControllerException(e.getMessage());
						} 
						catch (ExecutionException e) 
						{
							throw new ControllerException(e.getMessage());
						}
					})
					.filter(p->p!=null)
					.collect(Collectors.toList());
			
			prgList.addAll(newPrgList);
			
			//prgList.forEach(prg->repo.logPrgStateExec(prg));
			prgList.forEach(prg->System.out.println(prg));
			repo.setPrgList(prgList);
		} 
		catch (InterruptedException e) 
		{
			throw new ControllerException(e.getMessage());
		}
		
	}

	public void allStep() 
	{
		//executor = Executors.newFixedThreadPool(2);
		List<PrgState> prgList = this.removeCompletedPrg(repo.getPrgList());
		while(prgList.size()>0)
		{
			oneStepForAllPrg(prgList);
			
				prgList.stream().forEach(prg->
				{
					prg.getHeap().setContent(this.GarbageCollector(prg.getSymbolTable().getContent().values(),prg.getHeap().getContent()));
				});
			
			prgList = this.removeCompletedPrg(repo.getPrgList());
		}
		executor.shutdownNow();
		
		List<PrgState> temporaryList = repo.getPrgList();
		
			temporaryList.stream().forEach(prg->{prg.getFileTable().setContent(this.FileManager(prg.getFileTable()));});
		
		
		System.out.println("Extra printing............");
		temporaryList.forEach(prg->System.out.println(prg));
		
		repo.setPrgList(prgList);
	}
	

}
