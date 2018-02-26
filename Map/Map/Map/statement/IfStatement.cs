using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;
using Map.expression;

namespace Map.statement
{
    class IfStatement : IStatement
    {
        private IExpression cond;
        private IStatement trueSt, falseSt;

        public IfStatement(IExpression e, IStatement trueS, IStatement falseS)
        {
            cond = e;
            trueSt = trueS;
            falseSt = falseS;
        }

        public ProgramState execute(ProgramState ps)
        {
            if (cond.eval(ps.symbolTable) == 0)
                ps.exeStack.push(falseSt);
            else
                ps.exeStack.push(trueSt);
            return null;
        }

        public override String ToString()
        {
            return "if " + cond + " then " + trueSt + " else " + falseSt;
        }
    }
}
