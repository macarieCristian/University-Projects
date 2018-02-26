using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;
using Map.expression;

namespace Map.statement
{
    class PrintStatement : IStatement
    {
        private IExpression expr;

        public PrintStatement(IExpression ex)
        {
            expr = ex;
        }

        public ProgramState execute(ProgramState ps)
        {
            ps.outList.add(expr.eval(ps.symbolTable));
            return null;
        }

        public override String ToString()
        {
            return "Print(" + expr + ")";
        }
    }
}
