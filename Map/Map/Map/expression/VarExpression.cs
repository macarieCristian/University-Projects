using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;

namespace Map.expression
{
    class VarExpression : IExpression
    {
        private String varName;

        public VarExpression(String name)
        {
            varName = name;
        }

        public int eval(IDict<string, int> symbolTable)
        {
            if (symbolTable.contains(varName))
                return symbolTable.getValue(varName);
            throw new Exception("Variable not found!");
        }

        public override string ToString()
        {
            return varName;
        }
    }
}
