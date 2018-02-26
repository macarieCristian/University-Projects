using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Map.domain;

namespace Map.expression
{
    class ConstExpression : IExpression
    {
        private int constant;

        public ConstExpression(int val)
        {
            constant = val;
        }

        public int eval(IDict<string, int> symbolTable)
        {
            return constant;
        }

        public override String ToString()
        {
            return constant + "";
        }
    }
}
