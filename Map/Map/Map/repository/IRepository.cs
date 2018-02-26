using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;

namespace Map.repository
{
    public interface IRepository
    {
        ProgramState Program { get; set; }
        void logPrgStateExec();
    }
}
