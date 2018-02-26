package repository;

import java.util.List;

import domain.PrgState;

public interface IRepository 
{
	 public List<PrgState> getPrgList(); 
	 public void setPrgList(List<PrgState> psList);
	 public void addPrgState(PrgState ps);
	 public void logPrgStateExec(PrgState ps);
	
}
