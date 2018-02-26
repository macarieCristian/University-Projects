using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;

namespace Map.statement
{
    public interface IStatement
    {
        ProgramState execute(ProgramState ps);
    }
}
