using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;
using Map.expression;

namespace Map.statement
{
    class AssignStatement : IStatement
    {
        private String varName;
        private IExpression expr;

        public AssignStatement(String name,
                               IExpression ex)
        {
            varName = name;
            expr = ex;
        }

        public ProgramState execute(ProgramState ps)
        {
            IDict<String, int> symb = ps.symbolTable;
            int res = expr.eval(symb);
            if (symb.contains(varName))
                symb.update(varName, res);
            else
                symb.add(varName, res);
            return null;

        }

        public override string ToString()
        {
            return varName + "=" + expr;
        }
    }
}
