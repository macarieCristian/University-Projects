using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.repository;
using Map.domain;
using Map.statement;

namespace Map.controller
{
    class Controller
    {
        private IRepository repo;

        public Controller(IRepository rep)
        {
            repo = rep;
        }

        public void oneStep()
        {
            ProgramState ps = repo.Program;
            if (ps.exeStack.isEmpty())
                throw new Exception("Stack is empty!");
            IStatement stat = ps.exeStack.pop();
            stat.execute(ps);
            Console.WriteLine(ps);
            repo.logPrgStateExec();
        }

        public void allSteps()
        {
            ProgramState ps = repo.Program;
            if (ps.exeStack.isEmpty())
                throw new Exception("Stack is empty!");
            while (!ps.exeStack.isEmpty())
            {
                oneStep();
            }
        }
    }
}
