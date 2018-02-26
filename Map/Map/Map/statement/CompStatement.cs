using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;

namespace Map.statement
{
    class CompStatement : IStatement
    {
        private IStatement st1, st2;

        public CompStatement(IStatement s1,IStatement s2)
        {
            st1 = s1;
            st2 = s2;
        }

        public ProgramState execute(ProgramState ps)
        {
            ps.exeStack.push(st2);
            ps.exeStack.push(st1);
            return null;
        }

        public override string ToString()
        {
            return "(" + st1 + ";" + st2 + ")";
        }
    }
}
